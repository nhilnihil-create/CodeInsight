#include <bits/stdc++.h>

#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

struct Point {
  double x, y;
};

void printPoint(Point p) { printf("%.8f %.8f\n", p.x, p.y); }

void koch(int d, Point p1, Point p2) {
  if (d == 0) return;

  Point diff = {p2.x - p1.x, p2.y - p1.y};
  Point s, t, u;

  s.x = p1.x + diff.x / 3;
  s.y = p1.y + diff.y / 3;

  t.x = p1.x + diff.x * 2 / 3;
  t.y = p1.y + diff.y * 2 / 3;

  u.x = s.x + diff.x / 2 / 3 - sqrt(3) / 2 * diff.y / 3;
  u.y = s.y + diff.x * sqrt(3) / 2 / 3 + diff.y / 2 / 3;

  koch(d - 1, p1, s);
  printPoint(s);
  koch(d - 1, s, u);
  printPoint(u);
  koch(d - 1, u, t);
  printPoint(t);
  koch(d - 1, t, p2);
}

int main() {
  int n;
  cin >> n;
  Point p1 = {0., 0.}, p2 = {100., 0.};

  printPoint(p1);
  koch(n, p1, p2);
  printPoint(p2);
  return 0;
}

