#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (k < a[i]) break;
    int j = prev(upper_bound(all(b), k - a[i])) - b.begin();
    ans = max(ans, i + j);
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
