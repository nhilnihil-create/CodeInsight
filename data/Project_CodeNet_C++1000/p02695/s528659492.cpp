#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
#include <limits>
using namespace std;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for (int i = 0; i < (n); i++)
// 素因数分解
vector<pair<long long, long long>> prime_factorize(long long n)
{
  vector<pair<long long, long long>> res;
  for (long long p = 2; p * p <= n; ++p)
  {
    if (n % p != 0)
      continue;
    int num = 0;
    while (n % p == 0)
    {
      ++num;
      n /= p;
    }
    res.push_back(make_pair(p, num));
  }
  if (n != 1)
    res.push_back(make_pair(n, 1));
  return res;
}
int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  int a[50], b[50], c[50], d[50];
  rep(i, q)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  int ans = 0;
  for (int i1 = 1; i1 < m + 1; i1++)
  {
    for (int i2 = i1; i2 < m + 1; i2++)
    {
      for (int i3 = i2; i3 < m + 1; i3++)
      {
        for (int i4 = i3; i4 < m + 1; i4++)
        {
          for (int i5 = i4; i5 < m + 1; i5++)
          {
            for (int i6 = i5; i6 < m + 1; i6++)
            {
              for (int i7 = i6; i7 < m + 1; i7++)
              {
                for (int i8 = i7; i8 < m + 1; i8++)
                {
                  for (int i9 = i8; i9 < m + 1; i9++)
                  {
                    for (int i10 = i9; i10 < m + 1; i10++)
                    {
                      int tmp = 0;
                      int A[] = {0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
                      for (int j = 0; j < q; j++)
                      {
                        if (A[b[j]] - A[a[j]] == c[j])
                        {
                          tmp += d[j];
                        }
                      }
                      ans = max(ans, tmp);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}