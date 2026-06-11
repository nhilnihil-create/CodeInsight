#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX 200005
const llong mod = 1000000000 + 7;

int N, K;
int memo[MAX];

int main()
{
  llong sum = 0;
  scanf("%d%d", &N, &K);

  llong low = 0, high = 0;
  for (int i = 0; i < N + 1; i++)
  {
    low += i;
    high += N - i;
    if (i + 1 >= K)
    {
      sum += high - low + 1;
      sum %= mod;
    }
  }

  printf("%d", sum);

  return 0;
}