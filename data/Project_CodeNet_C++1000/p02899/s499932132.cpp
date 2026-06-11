#define _GLIBCXX_DEBUG
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  map<int,int> A;
  for(int i=0; i<N; i++){
    cin >> A[i+1];
  }
  int B[N];


  for(auto& i:A){
    B[i.second-1] = i.first;
  }
  
  for(int i=0; i<N; i++){
    cout << B[i] << " ";
  }

  
  return 0;
}