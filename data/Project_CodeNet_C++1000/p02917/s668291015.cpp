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
map<string,int> ma;
signed main() {
  int n;
  cin >> n;
  vector<int> a(n-1);
  rep(i,n-1) {
    cin >> a[i];
  }
  int ans = a[0]+a[n-2];
  rep(i,n-2) {
    ans += min(a[i],a[i+1]);
  }
  cout << ans << endl;

  return 0;
}