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

template <typename F>
void search(int n, int m, vector<int> &s, F f) {
  if (n + 1 == s.size()) {
    f();
  } else {
    for (int j = s.back(); j <= m; j++) {
      s.push_back(j);
      search(n, m, s, f);
      s.pop_back();
    }
  }
}

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> a(Q), b(Q), c(Q), d(Q);
  rep(i, Q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i];
    b[i];
  }

  int result = 0;
  vector<int> s(1, 1);
  search(N, M, s, [&]() {
    int score = 0;
    rep(i, Q) {
      if (s[b[i]] - s[a[i]] == c[i]) {
        score += d[i];
      }
    }
    result = max(result, score);
  });
  cout << result << endl;

  return 0;
}