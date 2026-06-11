#include <cstdio>
#include <cmath>

char memo[2*123456+1] = { 2, 1, 1, };

bool is_prime(int n) {
  if (!memo[n]) {
    if (n%2 == 0) memo[n] = 2;
    else {
      for (int x=3;x<=(int)sqrt(n);x+=2) {
        if (n%x == 0) {
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
  while (true) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;
    int cnt = 0;
    for (int x=n+1;x<=2*n;x++) {
      if (is_prime(x)) cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}