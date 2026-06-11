#include <cmath>
#include <cstdio>

struct Point {
  double x, y;
};

void koch(int d, Point a, Point b) {
  if (d == 0) return;
  Point s, t, u;
  double th = M_PI / 3;
  s.x = ((a.x * 2) + b.x) / 3;
  s.y = ((a.y * 2) + b.y) / 3;
  t.x = (a.x + (b.x * 2)) / 3;
  t.y = (a.y + (b.y * 2)) / 3;
  u.x = ((t.x - s.x) * cos(th)) - ((t.y - s.y) * sin(th)) + s.x;
  u.y = ((t.x - s.x) * sin(th)) + ((t.y - s.y) * cos(th)) + s.y;

  koch(d - 1, a, s);
  printf("%f %f\n", s.x, s.y);
  koch(d - 1, s, u);
  printf("%f %f\n", u.x, u.y);
  koch(d - 1, u, t);
  printf("%f %f\n", t.x, t.y);
  koch(d - 1, t, b);
}

int main() {
  int n;
  Point a, b;
  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;

  scanf("%d", &n);
  printf("%f %f\n", a.x, a.y);
  koch(n, a, b);
  printf("%f %f\n", b.x, b.y);
}

