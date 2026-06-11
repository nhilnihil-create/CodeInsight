#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(10, vector<int>(10, 0)));
  for (int i = 1; i <= n; ++i) {
    rep(j, 10) rep(k, 10) dp[i][j][k] = dp[i-1][j][k];
    int hd = i;
    while (hd >= 10) hd /= 10;
    int ld = i % 10;
    dp[i][hd][ld]++;
  }

  int ans = 0;
  rep(j, 10) rep(k, 10) ans += dp[n][j][k] * dp[n][k][j];
  cout << ans << endl;
  return 0;
}