#include <iostream>
using namespace std;

struct Point {
  double X, Y;
  Point(double x, double y) :X(x), Y(y) {}
};

double cross(Point p0, Point p1, Point p2) {
  Point a = Point(p1.X - p0.X, p1.Y - p0.Y);
  Point b = Point(p2.X - p0.X, p2.Y - p0.Y);
  return a.X * b.Y - a.Y * b.X;
}

bool is_contain(Point a, Point b, Point c, Point p) {
  double c1 = cross(a, b, p);
  double c2 = cross(b, c, p);
  double c3 = cross(c, a, p);
  if (c1 > 0 && c2 > 0 && c3 > 0) return true;
  if (c1 < 0 && c2 < 0 && c3 < 0) return true;
  return false;
}

int main() {
  double x1, y1, x2, y2, x3, y3, xp, yp;
  while (~scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp)) {
    Point a = Point(x1, y1);
    Point b = Point(x2, y2);
    Point c = Point(x3, y3);
    Point p = Point(xp, yp);
    if (is_contain(a, b, c, p)) puts("YES");
    else puts("NO");
  }
}
