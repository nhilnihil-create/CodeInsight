/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

bool CanMove(const Pair &p1, const Pair &p2) {
  return ((p1.first + p1.second) == (p2.first + p2.second) || (p1.first - p1.second) == (p2.first - p2.second));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, W;
  cin >> H >> W;
  if (H == 1 || W == 1) {
    cout << 1 << endl;
  } else {
    cout << (((W + 1) / 2LL) * ((H + 1LL) / 2LL) + (W / 2LL) * (H / 2LL)) << endl;
  }
  return 0;
}
