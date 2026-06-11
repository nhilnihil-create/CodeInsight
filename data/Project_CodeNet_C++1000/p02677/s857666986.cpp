#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;

  double th = 2 * PI * ((60 * h) + m) / 720;
  double tm = 2 * PI * m / 60;

  double xh = a * cosl(th);
  double yh = a * sin(th);
  double xm = b * cosl(tm);
  double ym = b * sin(tm);
  double dx = xh - xm;
  double dy = yh - ym;
  double ans = sqrt(dx * dx + dy * dy);
  cout << fixed << setprecision(15) << ans << endl;

  return 0;
}