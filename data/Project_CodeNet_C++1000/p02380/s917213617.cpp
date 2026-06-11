#include<cstdio>
#include<cmath>

int main(){
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  double d = c * acos(-1) / 180;
  double s = a * b * sin(d) / 2;
  double h = b * sin(d);
  double l = sqrt(pow(h,2) + pow(a - b * cos(d),2))
             + a + b;
  
  printf("%f\n%f\n%f\n", s, l, h);

  return 0;
}