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
  int dp1[3333][3333], dp2[3333][3333], a[3333], b[3333], n, T;
  void solve() {
    cin >> n >> T;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i] >> b[i];
      for (int j = 0; j <= T; ++j) {
        dp1[i][j] = dp1[i - 1][j];
        if (j - a[i] >= 0)
          dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - a[i]] + b[i]);
      }
    }
    for (int i = n; i >= 1; --i) {
      for (int j = 0; j <= T; ++j) {
        dp2[i][j] = dp2[i + 1][j];
        if (j - a[i] >= 0)
          dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - a[i]] + b[i]);
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= T - 1; ++j) {
        ans = max(ans, dp1[i - 1][j] + dp2[i + 1][T - 1 - j] + b[i]);
      }
    }
    cout << ans << "\n";
  }
} NSPACE;
int main() {
  FPEN;
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}