#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
  double x;
  double y;
};

static void CreateTriangle(const Point& p1, const Point& p2, int n) {
  if (n <= 0)
    return;

  static const double kCos60 = cos(60.0 * M_PI / 180.0);
  static const double kSin60 = sin(60.0 * M_PI / 180.0);

  Point s;
  s.x = (2 * p1.x + p2.x) / 3.0;
  s.y = (2 * p1.y + p2.y) / 3.0;

  Point t;
  t.x = (p1.x + 2 * p2.x) / 3.0;
  t.y = (p1.y + 2 * p2.y) / 3.0;

  Point u;
  const double dx = t.x - s.x;
  const double dy = t.y - s.y;
  u.x = s.x + dx * kCos60 - dy * kSin60;
  u.y = s.y + dx * kSin60 + dy * kCos60;

  CreateTriangle(p1, s, n - 1);
  printf("%f %f\n", s.x, s.y);
  CreateTriangle(s, u, n - 1);
  printf("%f %f\n", u.x, u.y);
  CreateTriangle(u, t, n - 1);
  printf("%f %f\n", t.x, t.y);
  CreateTriangle(t, p2, n - 1);
}

int main() {
  int n;
  scanf("%d", &n);

  Point p1;
  p1.x = 0;
  p1.y = 0;

  Point p2;
  p2.x = 100.0;
  p2.y = 0;

  printf("%f %f\n", p1.x, p1.y);
  CreateTriangle(p1, p2, n);
  printf("%f %f\n", p2.x, p2.y);

  return 0;
}