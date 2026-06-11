#include <cstdio>
#include <algorithm>
#include <utility>

int main()
{
  int n;
  using pair = std::pair<long long, long long>;
  pair crd[50];
  scanf("%d", &n);
  if (n == 1)
  {
    puts("1");
    return 0;
  }
  for (int i = 0; i < n; ++i)
  {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    crd[i] = pair{x, y};
  }
  std::sort(crd, crd + n);
  int ans = 1e9;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i == j || crd[j].first < crd[i].first) continue;
      if (crd[j].first == crd[i].second && crd[j].second < crd[i].second) continue;
      auto p = crd[j].first - crd[i].first;
      auto q = crd[j].second - crd[i].second;
      int cnt = 0;
      for (long long b = 0; b != (1LL << n) - 1;)
      {
        pair last;
        for (int i = 0; i < n; ++i)
        {
          if ((b >> i) & 1) continue;
          ++cnt;
          b |= 1LL << i;
          last = crd[i];
          break;
        }
        for (int i = 0; i < n; ++i)
        {
          if ((b >> i) & 1) continue;
          if (last.first + p == crd[i].first && last.second + q == crd[i].second)
          {
            b |= 1LL << i;
            last = crd[i];
          }
        }
      }
      if (ans > cnt) ans = cnt;
    }
  }
  printf("%d\n", ans);
  return 0;
}
