#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  ll n, k;
  cin >> n >> k;
  n %= k;
  cout << min(n, abs(n - k)) << endl;

  return 0;
}