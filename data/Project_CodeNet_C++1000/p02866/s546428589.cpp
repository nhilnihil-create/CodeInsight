#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e9;
const double EPS = 1e-9;
const ll MOD = 998244353;

ll repeatSquaring(ll n, ll p)
{
  if (p == 0)
    return 1;
  if (p % 2 == 0)
  {
    ll t = repeatSquaring(n, p / 2) % MOD;
    return t * t % MOD;
  }
  return n * repeatSquaring(n, p - 1) % MOD;
}

int main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> D(N);
  ll arr[100010] = {};
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &D[i]);
    arr[D[i]]++;
  }
  ll ans = 1;
  int cnt = arr[0];
  if (arr[0] != 1 || D[0] != 0)
  {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i < N; ++i)
  {
    if (cnt == N)
      break;
    ans = ans * repeatSquaring(arr[i - 1], arr[i]) % MOD;
    cnt += arr[i];
  }
  cout << ans << endl;

  return 0;
}
