#include <stdio.h>

int main() {
  int m, n, oddctr = 0, evenctr = 0;
  scanf("%d %d", &m, &n);

  for(int i = 2; i <= m; i++) {
    oddctr = oddctr + i - 1;
  }

  for(int i = 2; i <= n; i++) {
    evenctr = evenctr + i - 1;
  }

  printf("%d", oddctr + evenctr);
  return 0;
}
