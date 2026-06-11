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
  long long H;
  scanf("%lld", &H);
  long long W;
  scanf("%lld", &W);
  long long A;
  scanf("%lld", &A);
  long long B;
  scanf("%lld", &B);

  int x = 0, y = 1;
  for (int i = 0; i < H; ++i)
  {
    if (i >= B)
      x = 1, y = 0;
    for (int j = 0; j < W; ++j)
    {
      int n;
      if (j < A)
        n = x;
      else
        n = y;
      cout << n;
    }
    cout << endl;
  }

  return 0;
}
