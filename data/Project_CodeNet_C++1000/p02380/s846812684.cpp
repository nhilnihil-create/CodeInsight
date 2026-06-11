#include<cstdio>
#include<cmath>
using namespace std;

int main() {

  double a, b, c, S, PI = acos(-1), rad, L;

  scanf("%lf %lf %lf", &a, &b, &c);

  rad = (c * PI) / 180.0;

  S = (0.5) * a * b * sin(rad);
  L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2*a*b*cos(rad));
  
  printf("%f\n%f\n%f\n", S, L, (S / a) * 2.0);
  
  return 0;
}
