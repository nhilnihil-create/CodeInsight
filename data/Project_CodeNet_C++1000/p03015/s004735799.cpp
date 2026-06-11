#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MOD = 1e9+7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<ll>> dp(n+1, vector<ll>(2));
  dp[0][0] = 1;
  rep(i, n) rep(j, 2) {
    dp[i][j] %= MOD;
    if (j)
      dp[i+1][1] += dp[i][j]*3;
    else {
      if (s[i] == '1') {
        dp[i+1][0] += dp[i][j]*2;
        dp[i+1][1] += dp[i][j];
      } else
        dp[i+1][0] += dp[i][j];
    }
  }
  int ans = (dp[n][0]+dp[n][1])%MOD;
  cout << ans << endl;
  return 0;
}