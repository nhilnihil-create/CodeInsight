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

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  rep(i, N) { cin >> a[i]; }
  vector<int> b(a);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  if (N % 3 != 0) {
    cout << (b.size() == 1 && b[0] == 0 ? "Yes" : "No") << endl;
  } else {
    if (b.size() <= 3) {
      vector<int> cnt(b.size(), 0);
      rep(i, N) { cnt[lower_bound(b.begin(), b.end(), a[i]) - b.begin()]++; }
      int s = 0;
      rep(i, b.size()) {
        if (cnt[i] % (N / 3) != 0) {
          cout << "No" << endl;
          return 0;
        } else {
          rep(j, cnt[i] / (N / 3)) { s = s ^ b[i]; }
        }
      }
      cout << (s == 0 ? "Yes" : "No") << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}