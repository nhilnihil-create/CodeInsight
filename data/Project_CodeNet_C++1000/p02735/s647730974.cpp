#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pi pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#ifdef LOCAL
template <class T> ostream &operator<<(ostream &str, const vector<T> &vec) {
  str << '[';
  for (auto it = vec.begin(); it != vec.end(); it++) {
    if (it != vec.begin())
      str << ", ";
    str << *it;
  }
  str << ']';
  return str;
}
#define var(x) "[" << #x << ": " << x << "] "
#define dbg cerr << "  line " << __LINE__ << ": "
#else
#define var(x) 0
struct dbg_cls {
  template <class T> dbg_cls &operator<<(const T &oth) { return *this; }
} dbg;
#endif
using ll = long long;
int main(int argc, char **argv) {
#ifdef LOCAL
  int _time = clock();
#endif
  ios::sync_with_stdio(false), cin.tie(0);
  auto solve = [&]() {
    int n, m;
    cin >> n >> m;
    char c;
    vector<vector<bool>> v(n, vector<bool>(m));
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> c;
        v[i][j] = c == '#' ? 1 : 0;
      }
    }
#define dp(i, j) (i < 0 || j < 0 ? (int)1e9 : dp[i][j])
    dp[0][0] = v[0][0];
    for (int i = 1; i < n; i++)
      dp[i][0] = dp[i - 1][0] + (v[i][0] && !v[i - 1][0]);
    for (int j = 1; j < m; j++)
      dp[0][j] = dp[0][j - 1] + (v[0][j] && !v[0][j - 1]);
    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++)
        dp[i][j] = min(dp[i - 1][j] + (v[i][j] && !v[i - 1][j]),
                       dp[i][j - 1] + (v[i][j] && !v[i][j - 1]));
    cout << dp[n - 1][m - 1] << '\n';
  };
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
#ifdef LOCAL
  cerr << "Took " << (1000ll * ll(clock() - _time)) / CLOCKS_PER_SEC << "ms.\n";
#endif
  return 0;
}