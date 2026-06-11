#include <cstdio>

int A, V;
int B, W;
int T;

int main() {
  scanf("%d%d%d%d%d", &A, &V, &B, &W, &T);
  if (V <= W) {
    puts("NO");
    return 0;
  }
  int D = A < B ? B - A : A - B;
  if (D <= 1ll * T * (V - W)) {
    puts("YES");
  } else {
    puts("NO");
  }
}