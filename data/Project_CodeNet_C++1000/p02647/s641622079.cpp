#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  vector<int> C(N, N);
  rep(j,K){
    vector<int> B(N+1,0);
    rep(i,N){
      int Le = max(0, i-A[i]);
      int Ri = min(N, i+A[i]+1);
      B[Le]++;
      B[Ri]--;
    }
    rep(i,N) B[i+1]+=B[i];
    B.pop_back();
    if(A==B) break;
    A=B;
  }
  rep(i,N){
    cout << A[i] << endl;
  }
}