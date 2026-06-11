#include <stdio.h>
#include <math.h>
int main(void)
{
  int s[1000], n,i;
  double m, alpha, x;

  while(scanf("%d", &n), n!=0) {
    alpha=0;m=0;
    for(i=0;i<n;i++) {
      scanf("%d", &s[i]);
      m +=s[i];
    }
    m = m/n;
    for(i=0;i<n;i++) {
      x = s[i]-m;
      alpha += x*x;
    }
    printf("%lf\n", sqrt(alpha/n));
  }


  return 0;
}