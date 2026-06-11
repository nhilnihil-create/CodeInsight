#include <iostream>
#include <cmath>

int N;

typedef struct {
  double x;
  double y;
} grid;

void kochCurve(grid l, grid r, int n) {
  if (n >= N)
    return;
  ++n;
  grid s = {(2.0 * l.x + r.x) / 3.0, (2.0 * l.y + r.y) / 3.0};
  grid t = {(l.x + 2.0 * r.x) / 3.0, (l.y + 2.0 * r.y) / 3.0};
  grid u;
  u.x = (r.x - l.x) / 6.0 - (r.y - l.y) * sqrt(3.0) / 6.0 + s.x;
  u.y = (r.y - l.y) / 6.0 + (r.x - l.x) * sqrt(3.0) / 6.0 + s.y;
  kochCurve(l, s, n);
  std::cout << s.x << " " << s.y << std::endl;
  kochCurve(s, u, n);
  std::cout << u.x << " " << u.y << std::endl;
  kochCurve(u, t, n);
  std::cout << t.x << " " << t.y << std::endl;
  kochCurve(t, r, n);
}

int main() {
  std::cin >> N;
  grid l = {0.0, 0.0};
  grid r = {100.0, 0.0};
  std::cout << l.x << " " << l.y << std::endl;
  kochCurve(l, r, 0);
  std::cout << r.x << " " << r.y << std::endl;
  return 0;
}