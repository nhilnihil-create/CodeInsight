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
  int x, n;
  cin >> x >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    s.insert(t);
  }
  for (int i = 0; ; i++) {
    if (!s.count(x - i)) {
      cout << x - i << '\n';
      return;
    }
    if (!s.count(x + i)) {
      cout << x + i << '\n';
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
