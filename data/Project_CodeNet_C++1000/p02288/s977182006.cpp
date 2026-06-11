#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

#define A_MAX 500000
#define INVALID -2000000000

int A[A_MAX];

int parent(int i) {
    return i / 2;
}

int left(int i ) {
    return i * 2;
}

int right(int i ) {
    return i * 2 + 1;
}

void max_heapify(int i, int m) {
    int l = left(i);
    int r = right(i);
    int largest;
//    printf("max_heapify(%d, %d)\n", i, m);
    if (l <= m && A[l-1] > A[i-1]) {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r <= m && A[r-1] > A[largest-1]) {
        largest = r;
    }

    if (largest != i) {
        int tmp = A[i-1];
        A[i-1] = A[largest-1];
        A[largest-1] = tmp;
        max_heapify(largest, m);
    }
}

void build_max_heap(int m) {
    for (int i = m/2; i > 0; i--) {
        max_heapify(i, m);
    }
}

int main() {
    int m;

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    build_max_heap(m);

    for (int i = 0; i < m; i++) {
        cout << " " << A[i];
    }
    cout << endl;

    return 0;
}

