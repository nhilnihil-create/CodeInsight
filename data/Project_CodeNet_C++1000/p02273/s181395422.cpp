#include <iostream>
#include <cmath>
using namespace std;

class P {
public:
  double x, y;
};

void Koch(int n, P p1, P p2) {
  if (!n) return;

  const double PI = acos(-1.0);
  P s, t, u;
  s.x = (2 * p1.x + p2.x) / 3;
  s.y = (2 * p1.y + p2.y) / 3;
  t.x = (p1.x + 2 * p2.x) / 3;
  t.y = (p1.y + 2 * p2.y) / 3;
  u.x = (t.x - s.x) * cos(60 * PI / 180) - (t.y - s.y) * sin(60 * PI / 180) + s.x;
  u.y= (t.x - s.x) * sin(60 * PI / 180) + (t.y - s.y) * cos(60 * PI / 180) + s.y;

  Koch(n - 1, p1, s);
  cout << s.x << " " << s.y << endl;
  Koch(n - 1, s, u);
  cout << u.x << " " << u.y << endl;
  Koch(n - 1, u, t);
  cout << t.x << " " << t.y << endl;
  Koch(n - 1, t, p2);
}

int main() {
  int n; cin >> n;
  P p1, p2;
  p1.x = 0; p1.y = 0;
  p2.x = 100; p2.y = 0;

  cout << p1.x << " " << p1.y << endl;
  Koch(n, p1, p2);
  cout << p2.x << " " << p2.y << endl;

  return 0;
}
