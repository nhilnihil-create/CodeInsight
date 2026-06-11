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
  int l, r;
  cin >> l >> r;
  int ans = 2018;
  for (int i = l; i < min(l + 2018, r); i++)
  for (int j = i + 1; j <= min(l + 2018, r); j++) {
    ans = min(ans, (i * j) % 2019);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
