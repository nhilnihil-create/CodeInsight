#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, j, n) for (i64 i = (j); i < (n); ++i)
using namespace std;
using i64 = int64_t;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];

  i64 ans = n;
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      if (i == j)
        continue;
      i64 p = x[j] - x[i];
      i64 q = y[j] - y[i];

      i64 cnt = 0;
      rep(k, 0, n)
      {
        rep(l, 0, n)
        {
          if (k == l)
            continue;
          i64 r = x[l] - x[k];
          i64 s = y[l] - y[k];
          if (p == r && q == s)
            ++cnt;
        }
      }
      ans = min(ans, n - cnt);
    }
  }
  cout << ans;
}
