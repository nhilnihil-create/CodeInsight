#include <stdio.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int d = 1;
  while (d + d <= n) { d += d; }
  if (d == n) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  if (n & 1) {
    for (int i = 2; i < n; i += 2) {
      printf("%d %d\n", i, i + 1);
      printf("%d %d\n", i + 1, 1);
      printf("%d %d\n", 1, n + i);
      printf("%d %d\n", n + i, n + i + 1);
    }
    printf("%d %d\n", n + 1, 2);
  } else {
    for (int i = 2; i < d + 2; i += 2) {
      printf("%d %d\n", i, i + 1);
      printf("%d %d\n", i + 1, 1);
      printf("%d %d\n", 1, n + i);
      printf("%d %d\n", n + i, n + i + 1);
    }
    printf("%d %d\n", n + 1, 2);
    for (int i = d + 2; i <= n; i++) {
        printf("%d %d\n", i, n + d);
        printf("%d %d\n", (((i - d) & 1) == 0) ? (i - d + 1) : (n + i - d - 1), n + i);
    }
  }
  return 0;
}
