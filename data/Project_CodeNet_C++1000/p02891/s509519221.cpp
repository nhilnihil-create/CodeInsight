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

  int K;
  cin >> K;

  string t(s);
  t[0] = '$';

  int scnt = 0;
  rep(i, s.size() - 1) {
    if (s[i + 1] == s[i]) {
      s[i + 1] = '$';
      scnt++;
    }
  }

  int tcnt = 1;
  rep(i, t.size() - 1) {
    if (t[i + 1] == t[i]) {
      t[i + 1] = '$';
      tcnt++;
    }
  }

  if (s.back() != s[0]) {
    cout << (int64_t)scnt * K << endl;
  } else if (t.back() != s[0]) {
    cout << (int64_t)K / 2 * (scnt + tcnt) + (int64_t)K % 2 * scnt << endl;
  } else {
    cout << scnt + (int64_t)(K - 1) * tcnt << endl;
  }
  return 0;
}