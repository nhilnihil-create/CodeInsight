#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

void Edge(int a, int b) {
  printf("%d %d\n", a, b);
}

void Con(void) {
  Edge(1, 2);
  Edge(2, 3);
  Edge(3, n + 1);
  Edge(n + 1, n + 2);
  Edge(n + 2, n + 3);
  for (int t = 4; t < n; t += 2) {
    Edge(n + 1, t);
    Edge(t, t + 1);
    Edge(n + 1, n + t + 1);
    Edge(n + t + 1, n + t);
  }
}

int main(void) {
  scanf("%d", &n);
  if ((n & -n) == n) {
    puts("No");
    return 0;
  }
  puts("Yes");
  Con();
  if (~n & 1) {
    int k = 0;
    while ((1 << k + 1) < n) {
      ++k;
    }
    Edge(n, 1 << k);
    if (n - (1 << k) == 2) {
      Edge(2 * n, 3);
    } else {
      Edge(2 * n, 2 * n - (1 << k) + 1);
    }
  }
  return 0;
}
