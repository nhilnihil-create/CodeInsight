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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vc> a(n, vc(m));
  for (auto &i : a) for (auto &j : i) cin >> j;
  int ans = 0;
  for (int i = 0; i < (1 << n); i++)
  for (int j = 0; j < (1 << m); j++) {
    vector<vc> b(all(a));
    for (int k = 0; k < n; k++) {
      if (get_bit(i, k)) {
        for (int l = 0; l < m; l++) {
          b[k][l] = '.';
        }
      }
    }
    for (int k = 0; k < m; k++) {
      if (get_bit(j, k)) {
        for (int l = 0; l < n; l++) {
          b[l][k] = '.';
        }
      }
    }
    int cnt = 0;
    for (auto &k : b) for (auto &l : k) {
      if (l == '#') cnt++;
    }
    if (cnt == k) ans++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
