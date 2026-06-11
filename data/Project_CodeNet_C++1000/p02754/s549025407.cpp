#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX

int main()
{
  llong N, A, B;
  llong C, mod, div;
  scanf("%lld", &N);
  scanf("%lld%lld", &A, &B);

  C = A + B;

  div = N / C;
  mod = N % C;
  if (mod - A >= 0)
  {
    printf("%lld", (div + 1) * A);
  }
  else
  {
    printf("%lld", div * A + mod);
  }

  return 0;
}