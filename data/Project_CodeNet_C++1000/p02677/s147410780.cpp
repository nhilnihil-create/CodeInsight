#include <stdio.h>
#include <math.h>

using namespace std;
typedef long long llong;

#define MAX 1010
const llong mod = 1000000000 + 7;

int main()
{

  double a, b, h, m;
  scanf("%lf%lf%lf%lf", &a, &b, &h, &m);

  double th = m - h * 5.0 - m / 12.0;
  th = th / 30 * M_PI;
  if (th < 0.0)
  {
    th *= -1.0;
  }

  double c_square = a * a + b * b - 2 * a * b * cos(th);
  double c = sqrt(c_square);
  printf("%.16lf", c);
  return 0;
}