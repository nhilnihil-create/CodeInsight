#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int heap[500001];
int H;
int parent(int i)
{
    return i / 2;
}

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i + 1;
}

void maxHeapify(int A[], int i)
{
    int l = left(i);
    int r = right(i);
    int largest;
    if (l <= H && A[i] < A[l])
        largest = l;
    else
        largest = i;
    if (r <= H && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        swap(A[largest], A[i]);
        maxHeapify(A, largest);
    }
}

void buildHeap(int A[])
{
    for(int i = H/2; i >= 1; i--)
        maxHeapify(A,i);
}
int main()
{
    cin >> H;
    for(int i = 1; i<= H; i++)
        cin >> heap[i];
    buildHeap(heap);
    for(int i =1; i<= H; i++)
        printf(" %d", heap[i]);
    printf("\n");
    return 0;
}
