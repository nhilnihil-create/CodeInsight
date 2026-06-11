#include <stdio.h>

int	 main(void)
{
  int a,b;
  int d,r;
  double aa,bb,f;
  double ba = 1;

  scanf("%d%d",&a,&b);

  d = a / b;
  r = a % b;

  aa = a / ba;
  bb = b / ba;

  f = aa / bb;

  printf("%d %d %f\n",d,r,f);
  
  return(0);
}