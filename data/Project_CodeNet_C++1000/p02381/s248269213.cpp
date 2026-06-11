#include <cmath>
#include <cstdio>

int main() {
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    int s[1000];
    for (int i = 0; i < n; i++) {
      scanf("%d", &s[i]);
    }

    double m = 0;
    for (int i = 0; i < n; i++) {
      m += s[i];
    }
    m /= n;

    double a = 0;
    for (int i = 0; i < n; i++) {
      a += (s[i] - m) * (s[i] - m) / n;
    }
    a = sqrt(a);

    printf("%f\n", a);
  }

  return 0;
}
