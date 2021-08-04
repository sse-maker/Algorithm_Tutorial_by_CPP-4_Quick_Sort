//
//  main.cpp
//  4_Quick_Sort
//
//  Created by 세광 on 2021/08/04.
//

#include <iostream>

using namespace std;

class QuickSort {
public:
    QuickSort();
    ~QuickSort();
    
    void Ascending(int, int);
    void Decending(int, int);
    const int GetN() const;
    void Print();
    
private:
    int n;
    int *arr;
};

int main() {
    QuickSort *sort = new QuickSort;
    sort->Ascending(0, sort->GetN() - 1);
    sort->Print();
    sort->Decending(0, sort->GetN() - 1);
    sort->Print();
    delete sort;
}

QuickSort::QuickSort() {
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
}

QuickSort::~QuickSort() {
    delete [] arr;
    arr = NULL;
}

void QuickSort::Ascending(int start, int end) {
    if (start >= end) return; // 원소가 1개인 경우 그대로 두기
    int key = start;
    int left = start + 1;
    int right = end;
    while (left <= right) { // 엇갈릴 때까지 반복
        while (left <= end && arr[left] <= arr[key]) left++; // key 값보다 큰 값을 만날 때까지 반복
        while (right > start && arr[right] >= arr[key]) right--; // key 값보다 작은 값을 만날 때까지 반복
        if (left > right) { // 현재 엇갈린 상태면 right와 key 값을 교체
            int temp = arr[right];
            arr[right] = arr[key];
            arr[key] = temp;
        } else { // 엇갈리지 않았다면 right와 left를 교체
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    Ascending(start, right - 1);
    Ascending(right + 1, end);
}

void QuickSort::Decending(int start, int end) {
    if (start >= end) return; // 원소가 1개인 경우 그대로 두기
    int key = start;
    int left = start + 1;
    int right = end;
    while (left <= right) { // 엇갈릴 때까지 반복
        while (left <= end && arr[left] >= arr[key]) left++; // key 값보다 작은 값을 만날 때까지 반복
        while (right > start && arr[right] <= arr[key]) right--; // key 값보다 큰 값을 만날 때까지 반복
        if (left > right) { // 현재 엇갈린 상태면 right와 key 값을 교체
            int temp = arr[right];
            arr[right] = arr[key];
            arr[key] = temp;
        } else { // 엇갈리지 않았다면 right와 left를 교체
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    Decending(start, right - 1);
    Decending(right + 1, end);
}

const int QuickSort::GetN() const { return n; }

void QuickSort::Print() {
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
}
