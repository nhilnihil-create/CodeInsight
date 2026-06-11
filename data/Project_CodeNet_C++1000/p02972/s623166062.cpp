#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main(){
  ll n;cin >> n;
  vector<ll> a(n+1);
  for(ll i=1;i<=n;++i) cin >> a.at(i);

  vector<ll> cnt(n+1);
  ll ans = 0;
  for(ll i=n;i>=1;--i){
    ll sum = 0;
    for(ll j=i;j<=n;j+=i){
      sum += cnt.at(j);
    }
    if( sum%2 != a.at(i) ){
      cnt.at(i) = 1;
      ++ans;
    }
  }

  cout << ans << endl;
  if( ans == 0 ) return 0;
  for(ll i=1;i<=n;++i){
    if( cnt.at(i) == 1 ){
      cout << i;
      if( i != n ) cout << " ";
    }
  }
  cout << endl;

  return 0;
}
