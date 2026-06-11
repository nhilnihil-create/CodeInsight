#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N,K;
  cin >> N >> K;

  vector<int> A(N+1);
  for(int i = 0;i < N;i++) cin >> A[i];

  int limit = min(K,100);
  

  for(int i = 0;i < limit;i++) {

    vector<int> B(N+1);
    
    for(int j = 0;j < N;j++) {
      int l = max(0,j-A[j]);
      int r = min(N,j+A[j]+1);
      B[l]++; B[r]--;
    }

    for(int j = 0;j < N;j++) {
      B[j+1] += B[j];
      A[j] = B[j];
    }

  }

  for(int i = 0;i < N;i++) cout << A[i] << " ";
  cout << endl;

  

}
