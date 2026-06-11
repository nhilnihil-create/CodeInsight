#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#define chmin(x,y) x = min(x,y)

const ll INF = 1001002003004005006ll;

ll dp[305][305];

int main() {
  int n, k;
  cin >> n >> k;
  int m = n-k;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  h.insert(h.begin(),0);
  rep(i,n+1)rep(j,m+1) dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i)rep(j,i+1) {
    ll now = INF;
    rep(k,i) {
      chmin(now, dp[k][j]+max(0,h[i]-h[k]));
    }
    dp[i][j+1] = now;
  }
  ll ans = INF;
  rep(i,n+1) chmin(ans, dp[i][m]);
  cout<<ans<<endl;
  return 0;
}
