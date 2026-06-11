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
  int k; cin >> k;
  for (int i = 7 % k, ans = 1; ans <= (int)(1e6); i = (i * 10 + 7) % k, ans++) {
    if (i == 0) {
      cout << ans << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
