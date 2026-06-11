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
  int K;
  cin >> K;

  queue<int64_t> q;
  rep(i, 9) { q.push(i + 1); }

  rep(i, K - 1) {
    int64_t v = q.front();
    q.pop();
    int r = v % 10;
    for (int d = -1; d <= 1; d++) {
      int s = r + d;
      if (s < 0 || s > 9) {
        continue;
      }

      q.push(v * 10 + s);
    }
  }
  cout << q.front() << endl;
  return 0;
}