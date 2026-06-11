#include <iostream>
#include <cassert>
#include <queue>
#include <cmath>

#define INF 922337203685477580
typedef long long ll;

using namespace std;

typedef struct {
  double x, y;
} Point;

void solve(int d, Point p1, Point p2) {
  if (d == 0) return;

  Point s, t, u;
  t.x = (p1.x + 2 * p2.x) / 3;
  t.y = (p1.y + 2 * p2.y) / 3;
  s.x = (p1.x * 2 + p2.x) / 3;
  s.y = (p1.y * 2 + p2.y) / 3;

  double r3 = sqrt(3);
  u.x = (double)1/2*t.x - r3/2*t.y + (double)1/2*s.x + r3/2*s.y;
  u.y = r3/2*t.x + (double)1/2*t.y - r3/2*s.x + (double)1/2*s.y;

  solve(d - 1, p1, s);
  // print s,
  cout << s.x << " " << s.y << endl;
  solve(d - 1, s, u);
  // print u,
  cout << u.x << " " << u.y << endl;
  solve(d - 1, u, t);
  // print t,
  cout << t.x << " " << t.y << endl;
  solve(d - 1, t, p2);
}
int main() {
  int n;
  cin >> n;

  Point p1 = {0, 0};
  Point p2 = {100, 0};

  cout << p1.x << " " << p1.y << endl;
  solve(n, p1, p2);
  cout << p2.x << " " << p2.y << endl;
  return 0;
}