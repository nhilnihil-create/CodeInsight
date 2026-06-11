#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

double rad(const double d) { return d * M_PI / 180.0; }

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  const double hour_angle = static_cast<double>(30 * h) + 0.5 * m;
  const double min_angle = 6 * m;
  const double angle = abs(hour_angle - min_angle);
  const double c2 = a * a + b * b - 2 * a * b * cos(rad(angle));
  const double ans = sqrt(c2);
  printf("%.10f\n", ans);

  return 0;
}
