#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

typedef long long LL;

int read() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f *= -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}

int main() {
  int n = read();
  if (n & (n - 1)) {
    puts("Yes");
#define link(a, b) printf("%d %d\n", a, b)
    link(1, 2); link(2, n+3); link(n+3, n+1);
    link(n+1, n+2); link(n+2, 3);
    for (int i = 4; i < n; i += 2) {
      link(n+1, i); link(i, i+1);
      link(n+1, n+i+1); link(n+i, n+i+1);
    }
    if (~n & 1) {
      int k = 1;
      while ((k << 1) < n) k <<= 1;
      link(n, k);
      link(n+n, n+(n^1^k));
    }
  } else {
    puts("No");
  }
}
