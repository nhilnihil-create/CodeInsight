#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll K,N,d=0,dl=0;
  cin >> K >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  dl=K-A[N-1]+A[0];
  rep(i,N-1) {
    d=A[i+1]-A[i];
    if(d>dl)dl=d;
  }
  cout << K-dl << endl;
  return 0;
}