#define _GLIBCXX_DEBUG
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, Q;
  cin >> N >> K >> Q;
  int A[Q], B[N], C[N];
  
  for(int i=0; i<Q; i++) cin >> A[i];
  for(int i=0; i<N; i++){
    B[i]=K;
    C[i]=0;
  }
  
  for(int i=0; i<Q; i++){
    C[A[i]-1]++;
  }
  
  for(int i=0; i<N; i++){
    if(B[i]-Q+C[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
  
  return 0;
}