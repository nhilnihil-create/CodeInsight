#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;

int main() {
  double a, b, h, m;
  cin >> a >> b >> h >> m;

  double ra = (h / 12.0 + m / 60.0 / 12.0) * 360.0;
  double rb = m / 60.0 * 360.0;
  double r = min(fabs(ra - rb), fabs(360.0 + rb - ra)) * acos(-1) / 180.0;

  cout << fixed << setprecision(10) << sqrt(a * a + b * b - 2 * a * b * cos(r))
       << endl;
  return 0;
}
