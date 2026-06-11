#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  double x1, y1, x2, y2;
  scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

  double dx = abs(x1 - x2);
  double dy = abs(y1 - y2);
  double dis = sqrt(dx * dx + dy * dy);

  printf("%f\n", dis);

  return 0;
}
