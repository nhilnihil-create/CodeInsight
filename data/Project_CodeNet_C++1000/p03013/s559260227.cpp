#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
const ll d = 1000000007;

int main(){
  ll n,m;cin >> n >> m;
  vector<ll> a(m);
  rep(i,m) cin >> a.at(i);
  vector<ll> dp(n+1);
  dp.at(0) = 1;
  ll cnt = 0;
  for(ll i=1;i<=n;++i){
    if( cnt < m && a.at(cnt) == i ){
      ++cnt;
      continue;
    }
    if( i == 1 ){
      dp.at(i) += dp.at(i-1);
      dp.at(i) %= d;
    }else{
      dp.at(i) = dp.at(i-1) + dp.at(i-2);
      dp.at(i) %= d;
    }
  }
  // rep(i,n+1) cout << dp.at(i) << endl;
  cout << dp.back() << endl;
  return 0;
}
