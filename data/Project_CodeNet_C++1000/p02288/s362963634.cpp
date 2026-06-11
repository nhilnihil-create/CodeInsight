#include <stdio.h>
#include <stdlib.h>

int left(int i){ return i*2; }

int right(int i){ return i*2 + 1; }

void swap(int *x, int *y){
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int n;

void maxHeapify(int *arr, int i){
  int largest;
  int l = left(i), r = right(i);

  // choice largest key in this and parents
  if(l <= n && arr[l] > arr[i]) largest = l;
  else largest = i;
  if(r <= n && arr[r] > arr[largest]) largest = r;

  if(largest != i){ // if arr[i]'s parent key larger than arr[i]'s key
    swap(&arr[i], &arr[largest]);
    maxHeapify(arr, largest);
  }
}

void buildMaxHeap(int *arr){
  int i;
  for(i=n/2; i>=1; i--) maxHeapify(arr, i);
}

int main(void){
  int i;
  int *heap;

  // input and alloc
  scanf("%d", &n);
  heap = (int *)malloc(sizeof(int) * n);
  for(i=1; i<=n; i++) scanf("%d", &heap[i]);

  // build heap
  buildMaxHeap(heap);

  // output
  for(i=1; i<=n; i++) printf(" %d", heap[i]);
  printf("\n");

  return 0;
}