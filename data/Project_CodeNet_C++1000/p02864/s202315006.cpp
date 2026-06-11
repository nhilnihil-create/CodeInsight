#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#else
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
 public:
  int h[333];
  i64 dp[333][333];
  void chmin(i64 &a, i64 b) {
    if (a == -1)
      a = b;
    else
      a = min(a, b);
  }
  void solve() {
    int n, m;
    cin >> n >> m;
    m = n - m;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    i64 ans = -1;
    for (int i = 1; i <= n; ++i) {
      dp[i][1] = h[i];
      for (int j = 2; j <= i; ++j) {
        dp[i][j] = -1;
        for (int k = j - 1; k < i; ++k) {
          chmin(dp[i][j], dp[k][j - 1] + max(h[i] - h[k], 0));
        }
      }
      if (i >= m)
        chmin(ans, dp[i][m]);
    }

    cout << ans << '\n';
  }
} NSPACE;
int main() {
  FPEN;
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}