#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
typedef complex<long double> point;

int main() {
  int n; cin >> n;
  vector<point> v(n);
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    v[i] = point(x, y);
  }

  sort(v.begin(), v.end(), [](point& p, point& q) {
    return arg(p) < arg(q);
  });

  long double ans = 0;
  for (int i = 0; i < n; i++) {
    point p(0, 0);
    for (int j = 0; j < n; j++) {
      p += v[(i + j) % n];
      ans = max(ans, abs(p));
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}