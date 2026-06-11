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
  vector<int64_t> A(N + 1, 0);
  for (int64_t i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  vector<int64_t> counts(N + 1, 0);
  vector<int64_t> result;
  for (int64_t i = N; i >= 1; --i) {
    int64_t s = 0;
    for (int64_t j = 2 * i; j <= N; j += i) {
      s += counts[j];
    }
    s %= 2;
    counts[i] = (A[i] == s) ? 0 : 1;
    if (A[i] == s) {
      counts[i] = 0;
    } else {
      counts[i] = 1;
      result.push_back(i);
    }
  }
  cout << result.size() << endl;
  if (result.size() > 0) {
    for (int64_t i = 0; i < static_cast<int64_t>(result.size()); ++i) {
      if (i != 0) {
        cout << " ";
      }
      cout << result[i];
    }
    cout << endl;
  }

  return 0;
}
