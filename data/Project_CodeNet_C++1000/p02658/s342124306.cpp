#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  long long int array[N], max = 1e18, p = 1, f = 0, z = 0;
  
  for (int i = 0; i < N; i++) {
    scanf("%lld", &array[i]);
    f = (array[i] > max) ? 1 : f;
    p *= array[i];
    (array[i]) ? max /= array[i] : z = 1;
  }

  (z) ? puts("0") : ((f) ? puts("-1") : printf("%lld\n", p));
  return 0;
}