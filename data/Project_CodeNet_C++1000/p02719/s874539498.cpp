#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef unsigned long long llong;

#define MAX 1e18
const llong mod = 1000000000 + 7;

int main()
{
  llong N, K;
  llong prevN = MAX;
  scanf("%llu%llu", &N, &K);

  llong sub;
  if (N > K)
    N -= N / K * K;
  do
  {
    prevN = min(prevN, N);
    if (N > K)
      sub = N - K;
    else
      sub = K - N;

    N = sub;
  } while (N != prevN);

  printf("%llu\n", N);

  return 0;
}