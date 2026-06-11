#include<stdio.h>
int main()
{
  int a, b, d, r;
  double e,s,f;
  scanf("%d %d", &a, &b);
  d = a / b;
  r = a%b;
  e = a; s = b;
  f = e / s;
  printf("%d %d %0.9lf\n",d,r,f);
  return 0;
}