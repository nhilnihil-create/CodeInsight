#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  lvector x(n,0),y(n,0),v_(n,0);
  rep(i,n) cin>>x[i]>>y[i];
  map<P,vector<P>> mp;
  for(ll i=0;i<n;++i) {
    for(ll j=i+1;j<n;++j) {
      ll x_=x[i]-x[j], y_=y[i]-y[j];
      mp[P(x_,y_)].emplace_back(P(i,j));
      mp[P(-x_,-y_)].emplace_back(P(i,j));
    }
  }
  ll mx=0;
  for(auto i:mp) mx=max(mx, (ll)(i.second).size());
  const ll ans=n-mx;
  print(ans);
  return 0;
}
