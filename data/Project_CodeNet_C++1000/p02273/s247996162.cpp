#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

void printv(double x, double y) {
  cout << fixed << setprecision(8) << x << ' ' << y << endl;
}

struct pos {
  double x, y;
};

void koch(double sx, double sy, double ex, double ey, int n) {
  if (!n) {
    printv(sx, sy);
    return;
  }
  pos m1 = {(2 * sx + ex) / 3, (2 * sy + ey) / 3};
  pos m2 = {sx + (ex - sx) / 2 - (ey - sy) * sqrt(3) / 6,
            sy + (ey - sy) / 2 + (ex - sx) * sqrt(3) / 6};
  pos m3 = {(sx + 2 * ex) / 3, (sy + 2 * ey) / 3};

  koch(sx, sy, m1.x, m1.y, n - 1);
  koch(m1.x, m1.y, m2.x, m2.y, n - 1);
  koch(m2.x, m2.y, m3.x, m3.y, n - 1);
  koch(m3.x, m3.y, ex, ey, n - 1);
}

int main() {
  int c;
  cin >> c;
  koch(0, 0, 100, 0, c);
  printv(100, 0);
}

