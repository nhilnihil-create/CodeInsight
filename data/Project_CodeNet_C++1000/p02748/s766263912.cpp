/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t A, B, M;
  cin >> A >> B >> M;
  vector<int32_t> a(A);
  vector<int32_t> b(B);
  int32_t min_price = INT32_MAX;
  for (int32_t i = 0; i < A; ++i) {
    cin >> a[i];
  }
  for (int32_t i = 0; i < B; ++i) {
    cin >> b[i];
  }
  for (int32_t i = 0; i < M; ++i) {
    int32_t x, y, c;
    cin >> x >> y >> c;
    const int32_t c_price = a[x - 1] + b[y - 1] - c;
    if (c_price < min_price) {
      min_price = c_price;
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a[0] + b[0] < min_price) {
    min_price = a[0] + b[0];
  }
  cout << min_price << endl;

  return 0;
}
