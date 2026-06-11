/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<Pair> due_and_time(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> due_and_time[i].second >> due_and_time[i].first;
  }
  sort(due_and_time.begin(), due_and_time.end());
  int64_t ctime = 0LL;
  bool is_okay = true;
  for (int64_t i = 0; i < N; ++i) {
    ctime += due_and_time[i].second;
    if (ctime > due_and_time[i].first) {
      is_okay = false;
      break;
    }
  }
  if (is_okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
