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

  if (s.size() >= 2 && s.size() % 2 == 0) {
    bool b = true;
    rep(i, s.size()) {
      b = b && ((i % 2 == 0 && s[i] == 'h') || (i % 2 == 1 && s[i] == 'i'));
    }
    cout << (b ? "Yes" : "No") << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}