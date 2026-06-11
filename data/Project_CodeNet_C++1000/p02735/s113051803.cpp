#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> G(h + 1);
  rep(i, h) {
    string s;
    cin >> s;
    s = "." + s;
    G[i + 1] = s;
  }
  string s = "";
  rep(i, w + 1) { s += "."; }
  G[0] = s;
  int dp[h + 1][w + 1];
  rep(i, h + 1) dp[i][0] = 0;
  rep(i, w + 1) dp[0][i] = 0;
  repi(i, 1, h + 1) {
    repi(j, 1, w + 1) {
      if (i == 1 && j == 1) {
        if (G[i][j] == '#')
          dp[i][j] = 1;
        else
          dp[i][j] = 0;
        continue;
      }
      int up = dp[i - 1][j];
      int left = dp[i][j - 1];
      if (G[i - 1][j] != G[i][j]) up++;
      if (G[i][j - 1] != G[i][j]) left++;
      if (i - 1 == 0) up = INF;
      if (j - 1 == 0) left = INF;
      dp[i][j] = min(up, left);
    }
  }
  /* repi(i, 1, h + 1) {
    repi(j, 1, w + 1) { cout << dp[i][j]; }
    cout << endl;
  } */
  if (G[h][w] == '#') dp[h][w]++;
  cout << dp[h][w] / 2 << endl;
  return 0;
}
