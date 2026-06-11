#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#define FOR(i,b,e) for(int i=b;i<e;i++)
#define REP(i,n) FOR(i,0,n)
using namespace std;

struct Point { double x, y; };

void koch(int d, Point p1, Point p2) {
  if (d == 0) return;

  Point s, t, u;
  double th = M_PI / 3.0;
  
  s.x = (2 * p1.x + 1 * p2.x) / 3.0;
  s.y = (2 * p1.y + 1 * p2.y) / 3.0;

  u.x = (1 * p1.x + 2 * p2.x) / 3.0;
  u.y = (1 * p1.y + 2 * p2.y) / 3.0;

  t.x = s.x + (u.x - s.x) * cos(th) - (u.y - s.y) * sin(th);
  t.y = s.y + (u.x - s.x) * sin(th) + (u.y - s.y) * cos(th);

  koch(d - 1, p1, s);
  cout << s.x << " " << s.y << endl;
  koch(d - 1, s, t);
  cout << t.x << " " << t.y << endl;
  koch(d - 1, t, u);
  cout << u.x << " " << u.y << endl;
  koch(d - 1, u, p2);
}

int main() {
	cin.tie(0);
 	ios::sync_with_stdio(false);

  int n;
  Point l, r;
  l.x = 0.0; l.y = 0.0;
  r.x = 100.0; r.y = 0.0;

  cin >> n;

  cout << l.x << " " << l.y << endl;
  koch(n, l, r);
  cout << r.x << " " << r.y << endl;
}