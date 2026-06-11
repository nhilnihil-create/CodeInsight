#include <stdio.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)

typedef double llb;

llb abs(llb a) {
  return a > 0 ? a : -a;
}

int main(void) {
  int i, n, j;
  scanf("%d", &n);
  llb x[n], y[n], d[n], max;
  rep(i, n) scanf("%lf", &x[i]);
  rep(i, n) scanf("%lf", &y[i]);
  rep(i, n) d[i] = abs(x[i] - y[i]);
  /*rep(i, n) printf("%f ", d[i]);
  printf("\n");*/
  rep(i, n) if(max < d[i]) max = d[i];
  llb ans = 0;
  for(i = 1; i <= 3; ++i) {
    ans = 0;
    rep(j, n) ans += pow(d[j], (double)i);
    ans = pow(ans, 1.0 / (double)i);
    printf("%f\n", ans);
  }
  printf("%f\n", max);
  return 0;
}
