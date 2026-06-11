#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll N,K;
  cin >> N >> K;
  if(N < K){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> H(N);
  rep(i,N){
    cin >> H.at(i);
  }
  sort(H.begin(),H.end());
  ll ans = 0;
  rep(i,N-K){
    ans += H.at(i);
  }
  cout << ans << endl;
  return 0;
}