#include<cstdio>

int main(){
  double r;
  double pi = 3.141592653589;
  scanf("%lf" , &r);
  printf("%lf %lf\n", pi * r * r, 2.0 * pi * r);
  return 0;
}