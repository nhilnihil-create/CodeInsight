#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long int in[n], ai = 1e18, x= 1, y = 0, z= 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &in[i]);
    y = (in[i] > ai) ? 1 : y;
    x *= in[i];
    (in[i]) ? ai /= in [i] : z = 1;
  }
  (z) ? puts("0") : ((y) ? puts("-1") : printf("%lld\n", x));
  return 0;
}
