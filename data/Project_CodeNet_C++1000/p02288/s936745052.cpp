#include<bits/stdc++.h>
using namespace std;
#define MAX 2000000
void maxHeapify(int);
int B;
int A[MAX+1];
int main(){
  int i;
  cin >> B;
  for(i = 1; i <= B;i++){
    cin >> A[i];
  }
  for(i = B/2; i >= 1; i--){
    maxHeapify(i);
  }
  for(i = 1; i <=B; i++){
    printf(" %d",A[i]);
  }
  printf("\n");
  return 0;
}

void maxHeapify(int i){
  int right,left,largest;
  left = 2*i;
  right = (2*i)+1;
  if(left <= B && A[left] > A[i]){
    largest = left;
  }
  else{
    largest = i;
  }
  if(right <= B && A[right] > A[largest]){
    largest = right;
  }
  if(largest != i){
    swap(A[i],A[largest]);
    maxHeapify(largest);
  }
}