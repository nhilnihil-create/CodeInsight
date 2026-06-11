#include <cstdio>
#include <cmath>

int main(){
  int a, b, C;
  double c, PI, rad, S, L, h;
  PI = acos(-1);

  scanf("%d %d %d", &a, &b, &C);

  rad = C * PI / 180;
  S = a*b*sin(rad)/2;
  c = sqrt( a*a+b*b-2*a*b*cos(rad) );
  L = a + b + c;
  h = 2*S/a;

  printf("%lf\n", S);
  printf("%lf\n", L);
  printf("%lf\n", h);

}