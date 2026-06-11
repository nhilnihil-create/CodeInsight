#include <stdio.h>
#include <functional>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  llong A, B, N;
  scanf("%lld %lld %lld", &A, &B, &N);

  llong x = min(B - 1, N);

  printf("%lld\n", (A * x) / B);

  return 0;
}