#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, k;
  cin >> n >> k;
  vector<double> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = (a[i] + 1) / 2 + a[i - 1];
  }
  double ans = 0;
  for (int i = 1; i <= n - k + 1; i++) {
    ans = max(ans, a[i + k - 1] - a[i - 1]);
  }
  cout << fixed << setprecision(20) << ans << '\n';
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
