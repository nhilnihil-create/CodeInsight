#include <stdio.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(void) {
  int i, n, j;
  while( 1 ) {
    scanf("%d", &n);
    if(!n) break;
    double a[n], ave = 0, sum = 0;
    rep(i, n) {
      scanf("%lf", &a[i]);
      ave += a[i];
    }
    ave /= n;
    rep(i, n) sum += (a[i] - ave) * (a[i] - ave);
    sum /= n;
    sum = sqrt(sum);
    printf("%f\n", sum);
  }
  return 0;
}
