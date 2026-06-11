#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

void selectionSort(int A[], int N);

int main(){
  int N;
  int A[100];
  int i;

  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  selectionSort(A, N);

  return 0;
}

void selectionSort(int A[], int N){
  int i, j, minj;
  int count = 0;

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]) minj = j;
    }
    swap(A[i], A[minj]);
    if(i != minj) count++;
  }

  for(i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i == N-1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
  printf("%d\n", count);
}

