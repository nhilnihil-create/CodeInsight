#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n - 1);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  for (auto &i : c) cin >> i;
  int ans = 0, old = -2;
  for (auto &i : a) {
    ans += b[i - 1];
    if (old == i - 1) ans += c[i - 2];
    old = i;
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
