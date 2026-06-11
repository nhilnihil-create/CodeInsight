#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define ii pair<int, int>
#define OK (cerr << "OK" << endl)
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int, int>
#define all(x) x.begin(), x.end()
#define Matrix vector<vector<int>>
#define Mat(n, m, v) vector<vector<int>>(n, vector<int>(m, v))
#define endl '\n'

constexpr int INF = ((int64_t)2e18);
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5 + 3;

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  // cin >> t;
  t = 1;

  while (t--) {
    int n;
    cin >> n;

    int m;
    cin >> m;

    n = 2 * m + 1;
    int h = (n / 2) + 1;
    vector<ii> ans;

    for (int i = 1, j = h; i < j; ++i, --j) {
      ans.eb(i, j);
    }

    for (int i = h + 1, j = n; i < j; ++i, --j)
      ans.eb(i, j);

    for (int i = 0; i < m; ++i)
      cout << ans[i].ff << ' ' << ans[i].ss << endl;
  }
}