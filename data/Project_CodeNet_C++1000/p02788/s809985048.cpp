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

struct Event {
  int64_t x;
  int64_t num;
};

int main() {
  int N, D, A;
  cin >> N >> D >> A;

  using P = pair<int, int>;
  vector<P> enemy(N);
  rep(i, N) {
    int x, h;
    cin >> x >> h;
    enemy[i] = P(x, h);
  }
  sort(enemy.begin(), enemy.end());

  auto cmp = [](const Event& lh, const Event& rh) { return lh.x > rh.x; };
  priority_queue<Event, vector<Event>, decltype(cmp)> q(cmp);

  int64_t result = 0;
  int64_t cnt = 0;
  rep(i, N) {
    int x, h;
    tie(x, h) = enemy[i];

    while (!q.empty() && q.top().x <= x) {
      cnt -= q.top().num;
      q.pop();
    }

    int64_t res = (h + A - 1) / A - cnt;
    if (res > 0) {
      result += res;
      cnt += res;

      Event bomb = {(int64_t)x + 2 * D + 1, res};
      q.push(bomb);
    }
  }

  cout << result << endl;

  return 0;
}