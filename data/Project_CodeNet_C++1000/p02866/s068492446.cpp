#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
const ll dv = 998244353;

int main() {
  ll n;cin >> n;
  map<ll,ll> m;
  rep(i,n){
    ll num;cin >> num;
    ++m[num];
    if( i == 0 && num != 0 ){
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  for( auto p : m ){

    if( p.first == 0 && p.second != 1 ){
      cout << 0 << endl;
      return 0;
    }

    if( p.first == 0 ) continue;
    if( m[p.first-1] == 0 ){
      cout << 0 << endl;
      return 0;
    }
    
    rep(i,p.second){
      ans *= m[p.first-1];
      ans %= dv;
    }
  }
  cout << ans << endl;
  return 0;
}
