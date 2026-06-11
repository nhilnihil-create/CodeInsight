#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll N,sum=0;
  cin >> N;
  vector<ll> A(N),B(N,0),C(N,0),D(N,0);
  rep(i,N) {
    cin >> A[i];
    B[A[i]-1]++;
  }
  rep(i,N){
    if(B[i]>1) {
      C[i]=B[i]*(B[i]-1)/2;
      sum += C[i];
    }
    if(B[i]>2) D[i]=(B[i]-1)*(B[i]-2)/2;
  }
  rep(i,N){
    ll ans=0;
    ans = sum - C[A[i]-1] + D[A[i]-1];
    cout << ans << endl;
  }
  
  return 0;
}
