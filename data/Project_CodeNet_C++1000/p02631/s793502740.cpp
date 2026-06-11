#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;


int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);
  ll xor_all = a.at(0);
  for(ll i=1;i<n;++i){
    xor_all = xor_all ^ a.at(i);
  }
  rep(i,n){
    ll ans = xor_all ^ a.at(i);
    cout << ans;
    if( i != n-1 ) cout << ' ';
    else cout << '\n';
  }
return 0;
}