#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;

  vector<string> v(h);
  rep(i, 0, h) cin >> v[i];

  vector<vector<int>> dp(h, vector<int>(w, 1e9));
  if (v[0][0] == '#')
    dp[0][0] = 1;
  else
    dp[0][0] = 0;

  rep(i, 0, h) {
    rep(j, 0, w) {
      rep(k, 0, 2) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= h || nj >= w)
          continue;
        int add = 0;
        if (v[ni][nj] == '#' && v[i][j] == '.')
          add = 1;
        chmin(dp[ni][nj], dp[i][j] + add);
      }
    }
  }

  cout << dp[h - 1][w - 1] << endl;
}
