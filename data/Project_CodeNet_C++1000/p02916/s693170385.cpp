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
int dp[100100];
int cnt = 0;
signed main() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  int c[n-1];
  rep(i,n) {
    cin >> a[i];
    a[i]--;
    //cout << a[i] << endl;
  }
  rep(i,n) {
    cin >> b[i];
    //cout << b[i] << endl;
  }
  rep(i,n-1) cin >> c[i];
  
  int now = a[0];
  int pre = -100;
  int ans = 0;
  rep(i,n) {
    now = a[i];
    //cout << now << endl;
    if(now==pre+1) ans+=c[pre];
    ans+=b[now];
    pre = now;
    //cout << a[i]<<" "<<ans <<now<<b[now] << endl;
  }

  cout << ans << endl;
  return 0;
}