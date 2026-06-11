/*input
4.56425719433005567605

*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double s, t;
  s = 2.0*M_PI*(h+m/60.0)/12.0;
  t = 2.0*M_PI*m/60.0;
  double dx, dy;
  dx = a*cos(s)-b*cos(t);
  dy = a*sin(s)-b*sin(t);
  double ans = sqrt(dx*dx+dy*dy);
  // cout << ans << endl;
  printf("%.20lf\n", ans);
  // printf("%.20lf\n", 4.56425719433005567605);
}