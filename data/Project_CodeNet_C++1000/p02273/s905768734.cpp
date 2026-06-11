/*
 * c.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

const double PI = acos(-1.0);

/* typedef */

template <typename T>
struct Pt {
  T x, y;

  Pt() {}
  Pt(T _x, T _y) : x(_x), y(_y) {}
  Pt(const Pt& pt) : x(pt.x), y(pt.y) {}

  bool operator==(const Pt pt) const { return x == pt.x && y == pt.y; }
  Pt<T> operator+(const Pt pt) const { return Pt<T>(x + pt.x, y + pt.y); }
  Pt<T> operator-() const { return Pt<T>(-x, -y); }
  Pt<T> operator-(const Pt pt) const { return Pt<T>(x - pt.x, y - pt.y); }
  Pt<T> operator*(T t) const { return Pt<T>(x * t, y * t); }
  Pt<T> operator/(T t) const { return Pt<T>(x / t, y / t); }
  T dot(Pt v) const { return x * v.x + y * v.y; }
  T cross(Pt v) const { return x * v.y - y * v.x; }
  Pt<T> mid(const Pt pt) { return Pt<T>((x + pt.x) / 2, (y + pt.y) / 2); }
  T d2() { return x * x + y * y; }
  double d() { return sqrt(d2()); }

  Pt<T> rot(double th) {
    double c = cos(th), s = sin(th);
    return Pt<T>(c * x - s * y, s * x + c * y);
  }

  Pt<T> rot90() { return Pt<T>(-y, x); }

  bool operator<(const Pt& pt) const {
    return x < pt.x || (x == pt.x && y < pt.y);
  }

  void print(string format) {
    printf(("(" + format + ", " + format + ")\n").c_str(), x, y);
  }
  void print() { print("%.6lf"); }
};

typedef Pt<double> pt;
typedef vector<pt> vpt;

/* global variables */

/* subroutines */

void rec(int n, vpt &ps, pt p4) {
  if (n <= 0) {
    ps.push_back(p4);
    return;
  }

  pt &p0 = ps.back();

  pt p1 = (p0 * 2 + p4) / 3;
  pt p2 = p1 + (p1 - p0).rot(PI / 3);
  pt p3 = (p0 + p4 * 2) / 3;

  rec(n - 1, ps, p1);
  rec(n - 1, ps, p2);
  rec(n - 1, ps, p3);
  rec(n - 1, ps, p4);
}

/* main */

int main() {
  int n;
  cin >> n;

  vpt ps;
  ps.push_back(pt(0.0, 0.0));

  rec(n, ps, pt(100.0, 0.0));

  for (int i = 0; i < ps.size(); i++)
    printf("%.8lf %.8lf\n", ps[i].x, ps[i].y);
  return 0;
}