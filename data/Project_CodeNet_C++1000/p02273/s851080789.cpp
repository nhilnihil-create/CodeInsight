#include<iostream>
#include<cmath>
using namespace std;

struct Point {double x, y; };

void coch(Point p1, Point p2, int n) {
  double th = M_PI * 60.0 / 180.0;

  if (n == 0)
    return;

  Point s, t, u;

  s.x = (2 * p1.x + p2.x) / 3;
  s.y = (2 * p1.y + p2.y) / 3;

  t.x = (p1.x + 2 * p2.x) / 3;
  t.y = (p1.y + 2 * p2.y) / 3;

  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

  coch(p1, s, n - 1);
  printf("%.8f %.8f\n", s.x, s.y);

  coch(s, u, n - 1);
  printf("%.8f %.8f\n", u.x, u.y);

  coch(u, t, n - 1);
  printf("%.8f %.8f\n", t.x, t.y);

  coch(t, p2, n - 1);

}

int main() {
  int n;
  Point a, b;

  a.x = 0;
  a.y = 0;

  b.x = 100;
  b.y = 0;

  cin >> n;

  printf("%.8f %.8f\n", a.x, a.y);
  coch(a, b, n);
  printf("%.8f %.8f\n", b.x, b.y);

  return 0;

}

