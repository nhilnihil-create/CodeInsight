#include <stdio.h>

int main()
{ 
  int a,b,d,r;
  double f;
  scanf("%ld%ld",&a,&b);
  d = a / b;
  r = a % b;
  f = (double)a/b;

  printf("%ld %ld %lf\n",d,r,f);

  return 0;
}
  