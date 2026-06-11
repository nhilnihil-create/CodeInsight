#include <bits/stdc++.h>
using namespace std;

struct Point{
  double x, y;

  Point operator+(const Point &other) {
    Point ret;
    ret.x = x + other.x;
    ret.y = y + other.y;
    return ret;
  }

  Point operator-(const Point &other) {
    Point ret;
    ret.x = x - other.x;
    ret.y = y - other.y;
    return ret;
  }

  Point operator*(const double &c) {
    Point ret;
    ret.x = c * x;
    ret.y = c * y;
    return ret;
  }

  Point rotate(double a) {
    Point ret;
    ret.x = x * cos(a) - y * sin(a);
    ret.y = x * sin(a) + y * cos(a);
    return ret;
  } 

  void print() {
    printf("%.10f %.10f\n", x, y);
  }
};

void koch(Point p1, Point p2, int n) {
  if (n > 0) {
    Point s, t, u;
    s = p1 * (2/3.0) + p2 * (1/3.0);
    u = p1 * (1/3.0) + p2 * (2/3.0);
    t = s + (u - s).rotate(M_PI/3.0);
    koch(p1, s, n - 1);
    s.print();
    koch(s, t, n - 1);
    t.print();
    koch(t, u, n - 1);
    u.print();
    koch(u, p2, n - 1);
  }
}

int main() {
  Point p1 = {0, 0}, p2 = {100, 0};
  int n;
  cin >> n;
  p1.print();
  koch(p1, p2, n);
  p2.print();
}
