#include <algorithm>
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

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

vector<int64_t> factors(int64_t n) {
  vector<int64_t> result;
  for (int64_t d = 1; d * d <= n; d++) {
    if (n % d == 0) {
      result.push_back(d);
      if (n / d != d) {
        result.push_back(n / d);
      }
    }
  }
  return result;
}

int main() {
  int64_t N;
  cin >> N;

  auto f1 = factors(N);
  auto f2 = factors(N - 1);

  copy(f2.begin(), f2.end(), back_inserter(f1));

  int64_t result = 0;
  for (int64_t f : f1) {
    if (f == 1) {
      continue;
    }
    int64_t x = N;
    while (x % f == 0) {
      x /= f;
    }
    if (x % f == 1) {
      result++;
    }
  }
  cout << result << endl;

  return 0;
}