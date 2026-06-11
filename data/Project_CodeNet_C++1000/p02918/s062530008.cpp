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
  long long K;
  scanf("%lld", &K);
  std::string S;
  std::cin >> S;
  vector<pair<char, int>> v;
  char c = S[0];
  int sum = 1;
  int l = 0, r = 0;
  for (int i = 1; i < N; ++i)
  {
    if (c == S[i])
    {
      sum++;
    }
    else
    {
      v.emplace_back(c, sum);
      if (c == 'L')
        l++;
      else
        r++;
      c = S[i], sum = 1;
    }
  }
  v.emplace_back(c, sum);
  if (c == 'L')
    l++;
  else
    r++;
  if (l <= r)
    c = 'L';
  else
    c = 'R';
  for (int i = 1; i < v.size() - 1; ++i)
  {
    if (K == 0)
      break;
    if (c == v[i].first)
    {
      K--;
      v[i].first = (c == 'L') ? 'R' : 'L';
    }
  }
  if (K > 0)
  {
    if (v[0].first == c)
    {
      K--;
      v[0].first = (c == 'L') ? 'R' : 'L';
    }
  }
  if (K > 0)
  {
    if (v[v.size() - 1].first == c)
    {
      K--;
      v[v.size() - 1].first = (c == 'L') ? 'R' : 'L';
    }
  }
  int ans = 0;
  for (int i = 0; i < v.size(); ++i)
  {
    ans += v[i].second;
    if (v[i].first == 'L' && (i == 0 || v[i].first != v[i - 1].first))
    {
      ans--;
    }
    if (v[i].first == 'R' && (i == v.size() - 1 || v[i].first != v[i + 1].first))
    {
      ans--;
    }
  }
  cout << ans << endl;

  return 0;
}
