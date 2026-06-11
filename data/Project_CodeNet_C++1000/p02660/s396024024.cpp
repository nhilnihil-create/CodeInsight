#include <cstdio>
#include <vector>
#include <utility>

using namespace std;
using llong = long long;
using prime_factors = vector<pair<llong, llong>>;

#define MAX 1e12
const llong mod = 1000000000 + 7;

prime_factors pf_factory(llong N)
{
  prime_factors res;
  for (llong a = 2; a * a <= N; a++)
  {
    if (N % a != 0)
      continue;
    llong ex = 0;
    while (N % a == 0)
    {
      ++ex;
      N /= a;
    }
    res.push_back({a, ex});
  }
  if (N != 1)
    res.push_back({N, 1});
  return res;
}

int main()
{
  llong N;
  prime_factors primes;

  scanf("%lld", &N);

  primes = pf_factory(N);

  llong ans = 0;
  for (auto p : primes)
  {
    llong i = 1;
    while (p.second > 0)
    {
      if (p.second > i * 2)
      {
        ans++;
        p.second -= i;
        i++;
      }
      else
      {
        p.second = 0;
        ans++;
      }
    }
  }

  printf("%lld", ans);

  return 0;
}