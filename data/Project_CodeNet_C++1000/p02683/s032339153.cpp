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
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  int a[n][m];
  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
  int ans = 100000000;
  int all = 1 << n;
  for (int mask = 0; mask < all; mask++)
  {
    vector<int> vec(m);
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
      if ((mask >> i) & 1)
      {
        cost += c[i];
        for (int j = 0; j < m; j++)
        {
          vec[j] += a[i][j];
        }
      }
    }
    bool ok = true;
    for (int j = 0; j < m; j++)
    {
      if (vec[j] < x)
      {
        ok = false;
      }
    }
    if (ok)
    {
      ans = min(ans, cost);
    }
  }
  if (ans == 100000000)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
  }
  return 0;
}