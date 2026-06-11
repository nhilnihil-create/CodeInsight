#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<vector<ll>> dp(n+1, vector<ll>(n+1, LINF));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      rep(l, i) {
        if (l)
          chmin(dp[i][j], dp[l][j-1]+max(h[i-1]-h[l-1], 0));
        else
          chmin(dp[i][j], dp[l][j-1]+h[i-1]);
      }
    }
  }
  ll ans = LINF;
  rep(i, n+1)
    chmin(ans, dp[i][n-k]);
  cout << ans << endl;
  return 0;
}