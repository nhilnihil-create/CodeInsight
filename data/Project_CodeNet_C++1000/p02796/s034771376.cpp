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
const double EPS = 1e9;
const ll MOD = 1e9 + 7;

int main()
{
  long long N;
  scanf("%lld", &N);
  vector<pair<ll, ll>> v;
  for (int i = 0; i < N; i++)
  {
    ll X, L;
    scanf("%lld", &X);
    scanf("%lld", &L);
    v.emplace_back(X + L, X - L);
  }
  sort(v.begin(), v.end());
  ll t = -INF, ans = 0;
  for (int i = 0; i < N; ++i)
  {
    if (t <= v[i].second)
    {
      ans++;
      t = v[i].first;
    }
  }
  cout << ans << endl;

  return 0;
}
