#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main(){
  ll n,k;cin >> n >> k;
  vector<ll> psn(n);
  rep(i,k){
    ll d;cin >> d;
    rep(j,d){
      ll a;cin >> a;
      --a;
      psn.at(a)++;
    }
  }
  ll ans = 0;
  rep(i,n){
    if( psn.at(i) == 0 ) ++ans;
  }
  cout << ans << endl;
  return 0;
}