#include <stdio.h>

int main(void)
{
  long int a, b, d, r;
  double f;

  scanf("%ld %ld", &a, &b);

  d = a/b;
  r = a%b;
  f = (double)a/(double)b;

  printf("%ld %ld %.5lf\n",d, r, f);

  return 0;
}