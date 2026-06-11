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
  std::vector<long long> A(N);
  ll sum = 0;
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
    sum += A[i];
  }
  int itr = -1;
  ll left = 0;
  for (int i = 0; i < N; ++i)
  {
    if (left + A[i] > sum / 2)
    {
      itr = i;
      break;
    }
    if (itr < 0)
      left += A[i];
  }
  cout << min(abs(sum - 2 * left), abs(sum - 2 * (left + A[itr]))) << endl;

  return 0;
}
