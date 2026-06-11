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
  int H, W, A, B;
  cin >> H >> W >> A >> B;

  rep(i, H) {
    rep(j, W) { cout << ((i < B) == (j < A) ? 1 : 0); }
    cout << "\n";
  }

  return 0;
}