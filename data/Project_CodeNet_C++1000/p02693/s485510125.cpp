#include <stdio.h>

int main() {
  int K, A, B;
  scanf("%d %d %d", &K, &A, &B);
  int N = (B/K) * K;
  (N > B || N < A) ? puts("NG") : puts("OK");
  return 0;
}