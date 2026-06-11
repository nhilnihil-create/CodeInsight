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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int ans = 0;
  if (n % 2 == 0 && x == n / 2 && m % 2 == 0 && y == m / 2) ans++;
  cout << fixed << setprecision(10);
  cout << double(n) * double(m) / 2.0 << ' ' << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
