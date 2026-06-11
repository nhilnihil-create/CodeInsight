#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vector<vector<int>> dp(h, vector<int>(w, INF));

  auto ok = [&](int i, int j) { return (0 <= i && i < h && 0 <= j && j < w); };

  dp[0][0] = (int)(s[0][0] == '#') + (int)(s[h - 1][w - 1] == '#');
  rep(i, h) rep(j, w) {
    if (ok(i, j - 1)) {
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + (int)(s[i][j] != s[i][j - 1]));
    }
    if (ok(i - 1, j)) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + (int)(s[i][j] != s[i - 1][j]));
    }
  }
  cout << dp[h - 1][w - 1] / 2 << endl;
  return 0;
}
