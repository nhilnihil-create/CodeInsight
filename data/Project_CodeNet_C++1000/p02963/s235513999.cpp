#include <algorithm>
#include <bitset>
#include <boost/rational.hpp>
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

int main() {
  int64_t s;
  cin >> s;

  constexpr int64_t d = 1'000'000'000;
  cout << 0 << " " << 0 << " " << 1 << " " << d << " " << (s - 1 + d) / d << " "
       << (d - s % d) % d << endl;

  return 0;
}
