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
  std::string S;
  std::cin >> S;
  int cnt = 1;
  bool f = false;
  int i = 0;
  for (i = 1; i < S.size(); ++i)
  {
    if (S[i - 1] != S[i] || f)
    {
      cnt++;
      f = false;
    }
    else
    {
      i++;
      cnt++;
      f = true;
    }
  }
  if (f && i > S.size())
    cnt--;
  cout << cnt << endl;

  return 0;
}
