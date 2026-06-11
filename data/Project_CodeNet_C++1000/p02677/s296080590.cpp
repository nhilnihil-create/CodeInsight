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
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  h = (h * 60.0 + m) / 720.0 * atan(1.0) * 8.0;
  m = m / 60.0 * atan(1.0) * 8.0;
  cout << fixed << setprecision(10);
  double ans = sqrt(a * a + b * b - 2 * a * b * cos(h - m));
  cout << ans << '\n';
}  

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
