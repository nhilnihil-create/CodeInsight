#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> r(a);
  vector<ll> g(b);
  vector<ll> t(c);
  vector<ll> dp(x+y+c);
  
  rep(i,a) cin >> r[i];
  rep(i,b) cin >> g[i];
  rep(i,c) cin >> t[i];
  
  sort(r.begin(),r.end());
  reverse(r.begin(),r.end());
  sort(g.begin(),g.end());
  reverse(g.begin(),g.end());
  
  rep(i,x) dp[i] = r[i];
  rep(i,y) dp[x+i] = g[i];
  rep(i,c) dp[x+y+i] = t[i];
  
  sort(dp.begin(),dp.end());
  reverse(dp.begin(),dp.end());
  
  ll ans=0;
  
  rep(i,x+y) ans += dp[i];
  
  cout << ans << endl;
  
  return(0);
}