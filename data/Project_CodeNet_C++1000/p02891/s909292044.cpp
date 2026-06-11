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
const ll MOD = 1e9 + 7;

int main()
{
  std::string S;
  std::cin >> S;
  long long K;
  scanf("%lld", &K);
  vector<pair<char, int>> v;
  int sum = 0;
  for (int i = 0; i < S.size() - 1; ++i)
  {
    if (S[i] == S[i + 1])
    {
      sum++;
    }
    else
    {
      v.emplace_back(S[i], sum + 1);
      sum = 0;
    }
  }
  if (sum > 0)
    v.emplace_back(S[S.size() - 1], sum + 1);
  ll ans = 0;
  if (v.empty())
    ans = K / 2;
  else if (v.size() == 1)
  {
    ans += v[0].second * K / 2;
  }
  else
  {
    for (int i = 1; i < v.size() - 1; ++i)
    {
      ans += v[i].second / 2 * K;
    }
    if (v[0].first == v[v.size() - 1].first)
    {
      ans += v[0].second / 2 + v[v.size() - 1].second / 2;
      ans += (v[0].second + v[v.size() - 1].second) / 2 * (K - 1);
    }
    else
    {
      ans += v[0].second / 2 * K + v[v.size() - 1].second / 2 * K;
    }
  }
  cout << ans << endl;

  return 0;
}
