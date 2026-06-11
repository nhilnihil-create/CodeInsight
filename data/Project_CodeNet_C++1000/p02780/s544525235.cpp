#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll N,K;
  cin >> N >> K;
  vector<ll> P(N);
  vector<ll> Sum(N);
  rep(i,N){
    ll p;
    cin >> p;
    P.at(i) = p + 1;
    if(i == 0){
      Sum.at(0) = P.at(0);
    }
    else{
      Sum.at(i) = Sum.at(i-1) + P.at(i);
    }
  }
  ll M = Sum.at(K-1) - 0;
  rep(i,N-K){
    M = max(M,Sum.at(K+i)-Sum.at(i));
  }
  cout << fixed << setprecision(8);
  if(M % 2 != 0){
  cout << M/2 + 0.5 << endl;
  }
  else{
    cout << M/2 << endl;
  }
  return 0;
}