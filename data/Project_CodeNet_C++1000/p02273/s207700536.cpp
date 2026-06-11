#include <bits/stdc++.h>
using namespace std;
double deg60 = M_PI * 60.0 / 180.0;
struct Vec {
  double x;
  double y;
};
void printVec(Vec v) {
  cout << fixed << setprecision(12) << v.x << ' ' << v.y << endl;
}
void koch(int d, Vec p1, Vec p2) {
  if (d == 0) return;
  Vec s, t, u;
  s = Vec{(2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3};
  t = Vec{(p1.x + 2 * p2.x) / 3, (p1.y + 2 * p2.y) / 3};
  u = Vec{(t.x - s.x) * cos(deg60) - (t.y - s.y) * sin(deg60) + s.x,
          (t.x - s.x) * sin(deg60) + (t.y - s.y) * cos(deg60) + s.y};
  koch(d - 1, p1, s);
  printVec(s);
  koch(d - 1, s, u);
  printVec(u);
  koch(d - 1, u, t);
  printVec(t);
  koch(d - 1, t, p2);
}
int main() {
  int n;
  cin >> n;
  Vec p1{0, 0}, p2{100, 0};
  printVec(p1);
  koch(n, p1, p2);
  printVec(p2);
}
