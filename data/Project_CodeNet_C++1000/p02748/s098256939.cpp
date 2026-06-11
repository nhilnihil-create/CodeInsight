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
  int A, B, M;
  cin >> A >> B >> M;

  int amin = 100'000, bmin = 100'000;
  vector<int> a(A), b(B);
  rep(i, A) {
    cin >> a[i];
    chmin(amin, a[i]);
  }
  rep(i, B) {
    cin >> b[i];
    chmin(bmin, b[i]);
  }

  int result = amin + bmin;
  rep(i, M) {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    chmin(result, a[x] + b[y] - c);
  }
  cout << result << endl;
  return 0;
}