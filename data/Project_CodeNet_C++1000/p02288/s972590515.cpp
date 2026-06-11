#include <cstdio>

long Left(long i) {
    return 2 * i;
}

long Right(long i) {
    return (2 * i + 1);
}

void MaxHeapify(long A[], int size, int i) {
    int l = Left(i + 1) - 1;
    int r = Right(i + 1) - 1;
    int largest = i;
    if ( l < size && A[i] < A[l]) largest = l;
    if ( r < size && A[largest] < A[r]) largest = r;
    if (largest != i) {
        int tmp = A[i]; A[i] = A[largest]; A[largest] = tmp;
        MaxHeapify(A, size, largest);
    }

}

void BuildMaxHeap(long A[], int size) {
    for (int i=(size/2-1); 0<=i; i--) {
        MaxHeapify(A, size, i);
    }
}

int main() {
    int H;
    scanf("%d", &H);
    long A[H];
    for (int i=0; i<H; i++) scanf("%ld", &A[i]);

    BuildMaxHeap(A, H);
    for (int i=0; i<H; i++) printf(" %ld", A[i]);
    printf("\n");
}