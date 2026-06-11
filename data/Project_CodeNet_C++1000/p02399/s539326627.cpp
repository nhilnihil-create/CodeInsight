#include <stdio.h>
main()
{
  int a, b;
  scanf("%d %d",&a, &b);
 int d = a/b;
  int r =a%b;
  double f=1.0*a/b;
  printf("%d %d %lf\n",d ,r ,f);
  return 0;
}