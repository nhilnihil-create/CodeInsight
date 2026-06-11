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

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<int> red(A), green(B), rg(C);
  rep(i, A) { cin >> red[i]; }
  rep(i, B) { cin >> green[i]; }
  rep(i, C) { cin >> rg[i]; }

  sort(red.begin(), red.end());
  sort(green.begin(), green.end());

  sort(rg.begin(), rg.end());

  int j = A - X, k = B - Y;
  rrep(i, C) {
    const int item = rg[i];
    if (j < A && item > red[j] && (k >= B || red[j] < green[k])) {
      red[j] = item;
      j++;
    } else if (k < B && item > green[k]) {
      green[k] = item;
      k++;
    }
  }

  int64_t result = 0;
  rep(i, X) { result += red[i + A - X]; }
  rep(i, Y) { result += green[i + B - Y]; }
  cout << result << endl;

  return 0;
}