// J'aime
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define int unsigned long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

#define i1e18 1000000000000000000

void MAIN() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a));
  if (a[0] == 0) {
    cout << 0 << '\n';
    return;
  }
  int ans = 1;
  for (auto &t : a) {
    if (ans <= i1e18 / t) {
      ans *= t;
      if (ans > i1e18) {
        cout << -1 << '\n';
        return;
      }
    } else {
      cout << -1 << '\n';
      return;
    }
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
  while (T--) MAIN();
}
