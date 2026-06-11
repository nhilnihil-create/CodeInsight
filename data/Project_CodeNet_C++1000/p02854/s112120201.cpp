#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

using namespace std;

uint64_t diff_abs(uint64_t x, uint64_t y)
{
  return x > y ? x - y : y - x;
}

int main()
{
  uint64_t N;
  cin >> N;

  vector<uint64_t> A(N);
  N_TIMES(n, N) { cin >> A[n]; }

  vector<uint64_t> S(N + 1, 0);
  N_TIMES(n, N) {
    S[n + 1] = A[n] + S[n];
  }

  uint64_t L = S[N], m = 1e+18;
  N_TIMES(n, N - 1) {
    uint64_t x = S[n + 1], y = L - S[n + 1];
    m = min(m, diff_abs(x, y));
  }
  cout << m << endl;

  return 0;
}