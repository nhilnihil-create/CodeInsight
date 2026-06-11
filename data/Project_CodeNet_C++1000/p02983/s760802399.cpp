#include <algorithm>
#include <iostream>
using namespace std;
const int MOD = 2019;
int main() {
  int L, R, m{MOD};
  cin >> L >> R;
  R = min(R - L, MOD);
  L %= MOD;
  if (L+R>=MOD) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < R; ++i)
    for (int j = i; j < R; ++j) m = min(m, (L + i) * (L + j + 1) % MOD);
  cout << m << endl;
}
