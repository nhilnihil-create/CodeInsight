#include <stdio.h>
int main(void)
{
  long long A, B, V, W, X, T, L, M, N;
  scanf("%lld%lld%lld%lld%lld", &A, &V, &B, &W, &T);
  L = A - B;

  if (L < 0)
  {
    M = (-1 * (A - B));
  }
  else
  {
    M = A - B;
  }

  X = (V - W) * T;
  N = M - X;
  if (N <= 0)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}
