#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)

const long long MOD = 2;
using lli = long long int;

void solve(long long k, long long q, std::vector<long long> d,
           std::vector<long long> n, std::vector<long long> x,
           std::vector<long long> m)
{
  rep(i, q)
  {
    lli tmp = 0;
    lli ans = 0;
    if (n[i] <= k)
    {
      lli cur = 0;
      vector<int> a(n[i]);

      rep(j, n[i])
      {
        if (j == 0)
          a[j] = x[i];
        else
          a[j] = a[j - 1] + d[(j - 1) % k];
        a[j] %= m[i];
      }
      rep(j, n[i] - 1)
      {
        if (a[j] < a[j + 1])
          ans++;
      }
      cout << ans << endl;
    }
    else
    {
      lli neko = 0;
      rep(j, k)
      {
        tmp += d[j] % m[i];
        if ((d[j] % m[i]) == 0)
          neko++;
      }
      lli hoge = tmp * ((n[i] - 1) / k);
      neko = neko * ((n[i] - 1) / k);
      lli fuga = hoge;
      rep(j, (n[i] - 1) % k)
      {
        fuga += d[j] % m[i];
        if ((d[j] % m[i]) == 0)
          neko++;
      }
      //fuga -= d[0] % m[i];
      fuga += x[i] % m[i];
      cout << n[i] - 1 - (fuga / m[i]) - neko << endl;
    }
  }
}

int main()
{
  long long k;
  scanf("%lld", &k);
  long long q;
  scanf("%lld", &q);
  std::vector<long long> d(k - 1 - 0 + 1);
  for (int i = 0; i < k - 1 - 0 + 1; i++)
  {
    scanf("%lld", &d[i]);
  }
  std::vector<long long> n(q);
  std::vector<long long> x(q);
  std::vector<long long> m(q);
  for (int i = 0; i < q; i++)
  {
    scanf("%lld", &n[i]);
    scanf("%lld", &x[i]);
    scanf("%lld", &m[i]);
  }
  solve(k, q, std::move(d), std::move(n), std::move(x), std::move(m));
  return 0;
}
