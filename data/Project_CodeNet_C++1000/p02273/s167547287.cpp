#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

double sin60 = sqrt(3.) / 2.;

struct Pt {
  double x;
  double y;

  Pt operator+(const Pt& other) { return {x + other.x, y + other.y}; }
  Pt operator-(const Pt& other) { return {x - other.x, y - other.y}; }
  Pt operator/(double n) { return {x / n, y / n}; }
  Pt rotate60() { return {.5 * x - sin60 * y, sin60 * x + .5 * y}; }
};

void koch(vector<Pt>& pts, Pt src, Pt dst, int i) {
  if (!i) {
    pts.push_back(src);
  } else {
    auto step = (dst - src) / 3;
    auto p1 = src + step;
    auto p2 = p1 + step.rotate60();
    auto p3 = p1 + step;
    koch(pts, src, p1, i - 1);
    koch(pts, p1, p2, i - 1);
    koch(pts, p2, p3, i - 1);
    koch(pts, p3, dst, i - 1);
  }
}

int main() {
  int n;
  cin >> n;
  vector<Pt> buf;
  koch(buf, {0, 0}, {100, 0}, n);
  buf.push_back({100, 0});
  for (auto&& pt : buf) {
    cout << fixed << setprecision(8) << pt.x << " " << pt.y << endl;
  }
}

