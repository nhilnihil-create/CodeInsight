#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main(){
  ll n,m;cin >> n >> m;
  vector<ll> h(n);
  rep(i,n) cin >> h.at(i);
  vector<vector<ll>> v(n);
  rep(i,m){
    ll a,b;cin >> a >> b;
    --a;--b;
    v.at(a).push_back(b);
    v.at(b).push_back(a);
  }
  ll ans = 0;
  rep(i,n){
    ll mx = -1;
    rep(j,v.at(i).size()){
      mx = max(mx,h.at(v.at(i).at(j)));
    }
    if( v.at(i).size() == 0 || mx < h.at(i)){
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}