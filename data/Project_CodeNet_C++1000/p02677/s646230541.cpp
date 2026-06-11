#include <bits/stdc++.h>

typedef long double ld;

int main() {
  int A, B, H, M;
  scanf("%d %d %d %d", &A, &B, &H, &M);
  ld a = A;
  ld b = B;
  ld r1 = 2 * M_PI * (ld(H) / 12.0 + ld(M) / 60.0 / 12.0);
  ld r2 = 2 * M_PI * ld(M) / 60.0;
  ld diff = std::abs(r1 - r2);
  printf("%.18Lf\n", std::sqrt(a*a + b*b - 2 * a * b * std::cos(diff)));
}
