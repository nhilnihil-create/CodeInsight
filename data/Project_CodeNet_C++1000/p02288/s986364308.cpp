#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include <math.h>
#include<algorithm>
using namespace std;
#define MAX 500000

int H[MAX+1],n;

int parent(int i){
  return i/2;
}

int left(int i){
  return i*2;
}

int right(int i){
  return i*2+1;
}

void maxHeapify(int i){
  int l=left(i);
  int r=right(i);
  int largest;
  if(l<=n && H[l]>H[i]) largest=l;
  else largest=i;
  if(r<=n && H[r]>H[largest]) largest=r;

  if(largest!=i){
    swap(H[i],H[largest]);
    maxHeapify(largest);
  }
}

void buildMaxHeap(){
  for(int i=n/2;i>=1;i--){
    maxHeapify(i);
  }
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>H[i+1];
  }
  buildMaxHeap();

  for(int i=0;i<n;i++){
    cout<<" "<<H[i+1];
  }
  cout<<endl;

}

