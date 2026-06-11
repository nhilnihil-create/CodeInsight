#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

static const double PI = 3.14159265359;

struct Point {
  double x;
  double y;
};

void printPoint(const Point& p) {
  cout << p.x << " " << p.y << endl;
}

void koch(int d, Point p1, Point p2) {
  if (d == 0) return;

  Point s, t, u;
  s.x = (2 * p1.x + 1 * p2.x) / 3;
  s.y = (2 * p1.y + 1 * p2.y) / 3;
  t.x = (1 * p1.x + 2 * p2.x) / 3;
  t.y = (1 * p1.y + 2 * p2.y) / 3;
  u.x = (t.x - s.x) * cos(PI / 3) - (t.y - s.y) * sin(PI / 3) + s.x;
  u.y = (t.x - s.x) * sin(PI / 3) + (t.y - s.y) * cos(PI / 3) + s.y;

  koch(d - 1, p1, s);
  printPoint(s);
  koch(d - 1, s, u);
  printPoint(u);
  koch(d - 1, u, t);
  printPoint(t);
  koch(d - 1, t, p2);
}

int n;

int main() {
  cin >> n;
  cout << fixed << setprecision(8);
  Point p1 {0., 0.}, p2 {100., 0.};
  printPoint(p1);
  koch(n, p1, p2);
  printPoint(p2);
}

