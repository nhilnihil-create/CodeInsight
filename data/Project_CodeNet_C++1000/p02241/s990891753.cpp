#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(void) {
  int n, i, j, ans = 0;
  scanf("%d", &n);
  int a[n][n];
  char f[n];
  rep(i, n) rep(j, n) scanf("%d", &a[i][j]);
  rep(i, n) f[i] = 0;
  f[0] = 1;
  rep(i, n - 1) {
    int min = 10000, minx, miny;
    rep(j, n) {
      rep(k, n) {
        if(f[j] && !f[k] && a[j][k] >= 0 && a[j][k] < min) min = a[j][k], minx = j, miny = k;
      }
    }
    ans += min;
    f[miny] = 1;
  }
  printf("%d\n", ans);
  return 0;
}
