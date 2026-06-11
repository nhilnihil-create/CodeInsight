#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n; cin >> n;
  vector<vector<ii>> a(n);
  for (auto &i : a) {
    int k; cin >> k;
    i.resize(k);
    for (auto &j : i) {
      cin >> j.fi >> j.sc;
      j.fi--;
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    vector<int> b(n);
    for (int j = 0; j < n; j++) {
      if (get_bit(i, j)) b[j] = 1;
      else b[j] = 0;
    }
    int f = 0;
    for (int j = 0; j < n; j++) {
      if (get_bit(i, j)) {
        for (auto &k : a[j]) {
          if (b[k.fi] != k.sc) {
            f = 1;
            break;
          }
        }
        if (f) break;
      }
    }
    if (!f) ans = max(ans, (int)__builtin_popcount(i));
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
