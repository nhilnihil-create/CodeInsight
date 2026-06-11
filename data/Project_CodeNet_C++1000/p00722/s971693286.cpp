#include <cstdio>
#include <cmath>

char memo[1000003] = { 2, 2, 1, 1 };

bool is_prime(int n) {
  if (!memo[n]) {
    if (n%2 == 0) memo[n] = 2;
    else {
      for (int i=3;i<=sqrt(n);i+=2) {
        if (n%i == 0) {
          memo[n] = 2;
          break;
        }
      }
      if (!memo[n]) memo[n] = 1;
    }
  }
  return (memo[n] == 1);
}

int main() {
  int a, d, n;
  while (true) {
    scanf("%d %d %d", &a, &d, &n);
    if (a == 0 && d == 0 && n == 0) break;
    int x = a, cnt = 1;
    do {
      while (!is_prime(x)) x += d;
      x += d;
    } while (cnt++ < n);
    printf("%d\n", x-d);
  }
  return 0;
}