#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  int P = (A1 - B1) * T1, Q = (A2 - B2) * T2;

  if (P > 0) {
    P *= -1;
    Q *= -1;
  }

  if (P + Q < 0) {
    cout << 0 << endl;
  } else if (P + Q == 0) {
    cout << "infinity" << endl;
  } else if (P + Q > 0) {
    int S = abs(P) / abs(P + Q), T = abs(P) % abs(P + Q);
    if (T != 0) {
      cout << 2 * S + 1 << endl;
    } else {
      cout << 2 * S << endl;
    }
  }

  return 0;
}
