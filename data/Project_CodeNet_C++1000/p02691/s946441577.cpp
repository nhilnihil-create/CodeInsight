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
/*  i <= j;
  j - i = A_i + A_j;
  j-A_j=x;
  i+A_i=x;
  */
int main()
{
  int n;
  cin >> n;
  map<ll, ll> L, R;
  ll ans = 0;
  rep(i, n)
  {
    ll A;
    cin >> A;
    ans += L[i - A];
    ans += R[i + A];
    L[i + A]++;
    R[i - A]++;
  }
  cout << ans << endl;
  return 0;
}