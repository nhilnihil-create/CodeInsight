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
  int n, m;
  cin >> n >> m;
  int a[m];
  ll ans=0;
  rep(i,m) {
    cin >> a[i];
    ans += a[i];
  }
  cout << max(n-ans,(ll)-1) << endl;
  return 0;
}
