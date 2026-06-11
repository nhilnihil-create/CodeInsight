#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int main() {
  int N;
  cin >> N;

  int64_t result = (int64_t)N * (N + 1) * (N + 2) / 6;
  rep(i, N - 1) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }

    result -= (int64_t)u * (N - v + 1);
  }
  cout << result << endl;
  return 0;
}