#include <stdio.h>

int main()
{
  int n, x, i, j, k, count;
  while (true) {
    count = 0;
    scanf("%d %d", &n, &x);
    if (n == 0 && x == 0) break;
    if (n >= 3 && n <= 100) {
      if (x >= 0 && x <= 300) {
        for (i = 1; i <= n; i++) {
          for (j = i + 1; j <= n; j++) {
            for (k = j + 1; k <= n; k++) {
              if (i + j + k == x) count++;
            }
          }
        }
      }
      printf("%d\n", count);
    }
  }
}

