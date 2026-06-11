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
  int N;
  cin >> N;
  vector<int> p(N);
  for (auto &e : p)
    cin >> e;
  vector<int> q(N);
  iota(q.begin(), q.end(), 1);

  int cnt = 0;
  for (int i = 0; i < N; ++i)
  {
    if (p[i] != q[i])
      cnt++;
  }
  if (cnt <= 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}