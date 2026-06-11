#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void MAIN() {
  int x, k, d;
  cin >> x >> k >> d;
  x = abs(x);
  int t = min(x / d, k);
  k -= t;
  x -= t * d;
  int ans = x;
  if (k % 2) ans = abs(x - d);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
