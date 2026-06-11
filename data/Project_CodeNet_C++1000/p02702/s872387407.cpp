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
  string s;
  cin >> s;
  int n = s.size();
  vector<ll> cum(n + 1);
  vector<ll> val(2019, 0);
  cum[0] = 0;
  ll fac = 1;
  val[0]++;
  for (int i = 1; i <= n; i++)
  {
    int add = s[n - i] - '0';
    cum[i] = (fac * add + cum[i - 1]) % 2019;
    fac = (fac * 10) % 2019;
    val[cum[i]]++;
  }
  ll ans = 0;
  for (int i = 0; i < 2019; i++)
  {
    ans += val[i] * (val[i] - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}