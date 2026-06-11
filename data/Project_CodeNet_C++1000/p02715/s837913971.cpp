#include <bits/stdc++.h>
#define DEBUG if(0)
#define lli long long int
#define ldouble long double
using namespace std;

const int maxN = 1e5;
lli ans[maxN + 1];
const lli mod = 1e9 + 7;

lli modPow(lli x, lli y)
{
  lli ans = 1;
  while (y)
  {
    if (y & 1LL) ans = ans * x % mod;
    x = x * x % mod, y >>= 1LL;
  }
  return ans;
}

int main()
{
  int n, k;
  while (scanf("%d %d", &n, &k) != EOF)
  {
    for (int i = k; i >= 1; i--)
    {
      ans[i] = modPow(k / i, n);
      for (int j = 2; i * j <= k; j++)
        ans[i] = (ans[i] - ans[i * j] + mod) % mod;
    }
    for (int i = 1; i <= k; i++)
      ans[i] = ans[i] * i % mod;

    lli total = 0;
    for (int i = 1; i <= k; i++)
      total = (total + ans[i]) % mod;
    printf("%lld\n", total);
  }
  return 0;
}