#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 500000;

int heap[MAX+1], h;

int buildHeap(int k){
  int left = 2*k, right = 2*k+1,large = 0;
  if  (right <= h && heap[left] < heap[right]){
    large = right;
  }else if (left <= h){
    large = left;
  }

  if (heap[k] < heap[large] && large != 0){
    swap(heap[k],heap[large]);
    buildHeap(large);
  }


}

int main(void){
  cin >> h;

  for (int i = 1; i<h+1; i++) cin >> heap[i];
  for (int i = h/2; i >= 1; i--) buildHeap(i);

  for (int i = 1; i<h+1; i++) cout << " " << heap[i];
  cout << endl;

  return 0;
}