#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
  public:
  int idx, x, y;
  double rad;
  Point(int _idx = 0, int _x = 0, int _y = 0) {
    idx = _idx; x = _x; y = _y;
    rad = atan2(x, y);
  }
};

int main() {
  int n; cin >> n;
  vector<int> xs(n), ys(n);
  vector<Point> ps(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i] >> ys[i];
    ps[i] = Point(i, xs[i], ys[i]);
  }

  sort(ps.begin(), ps.end(),
  [](Point const &a, Point const &b) -> bool { return a.rad < b.rad; });

  double ans = 0.0;
  for (int s = 0; s < ps.size(); s++) {
    double px = ps[s].x, py = ps[s].y;
    double tmp = sqrt(px * px + py * py);
    for (int c = 1; c < ps.size(); c++) {
      int e = (s + c) % ps.size();
      px += ps[e].x; py += ps[e].y;
      double next = sqrt(px * px + py * py);
      if (next < tmp) {
        break;
      }
      tmp = next;
    }
    if (ans < tmp) {
      ans = tmp;
    }
  }
  printf("%.10lf\n", ans);

  return 0;
}