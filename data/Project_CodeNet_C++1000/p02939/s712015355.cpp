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
  string s;
  cin >> s;

  vector<int> t;
  char curr = s[0];
  t.push_back(0);
  for (char c : s) {
    if (curr != c) {
      t.push_back(0);
      curr = c;
    }
    t.back()++;
  }

  int result = 0;
  int r = 0;
  for (int a : t) {
    result += r;
    a -= r;
    result += a / 3 * 2;
    if (a % 3 != 0) {
      result += 1;
    }
    if (a % 3 == 2) {
      r = 1;
    } else {
      r = 0;
    }
  }
  cout << result << endl;
  return 0;
}