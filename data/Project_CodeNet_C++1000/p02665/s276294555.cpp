#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
#define ll long long

signed main() {
  int n;
  cin >>n;
  vector<int> a(n+1);
  rep(i,n+1) cin >> a[i];
  vector<pair<int,int>> p(n+1);
  p[n] = {a[n],a[n]};
    //cout << n<<" "<<a[n]<<" "<<a[n] << endl;
  rrep(i,n) {
    p[i] = {(p[i+1].first+1)/2+a[i], p[i+1].second+a[i]};
    //cout << i<<" "<<(a[i+1]+1)/2+a[i]<<" "<<a[i+1]+a[i] << endl;
  } 
  if(p[0].first!=1) {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  int now = 1;
  rep(i,n+1) {
    ans += min(p[i].second,now);
    now =2*(min(p[i].second,now)-a[i]);
  }
  cout << ans << endl;
  return 0;
}