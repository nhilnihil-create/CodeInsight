#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int gcd(int a, int b)
{
  if (a % b == 0)
  {
    return (b);
  }
  else
  {
    return (gcd(b, a % b));
  }
}

int main()
{
  int K;
  llong ans = 0;
  scanf("%d", &K);
  for (int i = 1; i <= K; i++)
  {
    for (int j = 1; j <= K; j++)
    {
      for (int k = 1; k <= K; k++)
      {
        ans += gcd(gcd(i, j), k);
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}