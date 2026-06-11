#include <cstdio>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if(n & 1)
    for(int i = 1; i <= m; i++) printf("%d %d\n", i, n - i);
  else
    for(int i = 1; i <= m; i++)
      printf("%d %d\n", i, n - i - (i >= (n + 3) / 4));
}