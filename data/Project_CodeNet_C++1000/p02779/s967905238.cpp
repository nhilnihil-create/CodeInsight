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
  int n; cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    s.insert(t);
  }
  if (s.size() == n) cout << "YES" << '\n';
  else cout << "NO" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
