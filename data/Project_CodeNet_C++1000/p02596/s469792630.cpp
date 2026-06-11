#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6 + 12;

int k;
bitset<MN> bs;

int main (void) {
  ios::sync_with_stdio(false);cin.tie(0);
  cin >> k;
  int cur = 0;
  bs.reset();
  int res = 0;
  while (true) {
    res++;
    cur = (cur * 10 + 7) % k;
    if (cur == 0) {
      cout << res << '\n';
      return 0;
    } else if (bs[cur]) {
      cout << -1 << '\n';
      return 0;
    } else {
      bs[cur] = true;
    }
  }
  return 0;
}

