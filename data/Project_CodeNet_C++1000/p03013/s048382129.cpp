#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= m; i++) {
    int t; cin >> t;
    b[t] = 1;
  }
  a[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (b[i]) continue;
    (a[i] += a[i - 1]) %= MOD;
    if (i >= 2) (a[i] += a[i - 2]) %= MOD;
  }
  cout << a[n] << '\n';
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
