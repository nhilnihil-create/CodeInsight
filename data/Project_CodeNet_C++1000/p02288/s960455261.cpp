#include <iostream>
#include <bits/stdc++.h>
#define MAX_SIZE 500010
#define INFTY 2000000000
using namespace std;

int H;
int A[MAX_SIZE];

int left(int i) {
    return 2 * i;
}
int right(int i) {
    return 2 * i + 1;
}
int parent(int i) {
    return i / 2;
}

void maxHeapify(int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);
    if (l <= H && A[l] > A[i]) {
        largest = l;
    } 
    if (r <= H && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

void buildMaxHeap() {
    for (int i=H/2; i > 0; i--) {
        maxHeapify(i);
    }
}

int main(){
    int a;
    cin >> H;
    for (int i=1; i <= H; i++) {
        scanf("%d", &a);
        A[i] = a;
    }
    buildMaxHeap();
    for (int i=1; i <= H; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
    return 0;
} 
