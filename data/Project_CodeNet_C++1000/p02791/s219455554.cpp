#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int ans = 0, mi = 2e9;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    if (t < mi) ans++;
    mi = min(mi, t);
  }
  cout << ans << '\n';
}
