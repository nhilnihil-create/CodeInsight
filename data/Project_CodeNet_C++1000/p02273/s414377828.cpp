#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define PRINT(a) printf("%.8f %.8f\n", (a).x, (a).y)

struct Point { double x, y; };

void koch(int n, Point p1, Point p2) {
  double th =  60.0 * M_PI / 180.0;
  Point s = {
    (2.0 * p1.x + 1.0 * p2.x) / 3.0,
    (2.0 * p1.y + 1.0 * p2.y) / 3.0
  };
  Point t = {
    (1.0 * p1.x + 2.0 * p2.x) / 3.0,
    (1.0 * p1.y + 2.0 * p2.y) / 3.0
  };
  Point u = {
    (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x,
    (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y
  };

  if (n == 0) return;

  koch(n - 1, p1, s); PRINT(s);
  koch(n - 1, s, u); PRINT(u);
  koch(n - 1, u, t); PRINT(t);
  koch(n - 1, t, p2);
}

int main() {
  int n;
  Point p1 = {0.0, 0.0}, p2 = {100.0, 0.0};

  cin >> n;

  PRINT(p1);
  koch(n, p1, p2);
  PRINT(p2);

  return 0;
}