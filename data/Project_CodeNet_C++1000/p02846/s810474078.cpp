#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
    cout << "infinity" << endl;
  } else if ((t1 * a1 > t1 * b1) == (t1 * a1 + t2 * a2 > t1 * b1 + t2 * b2)) {
    cout << 0 << endl;
  } else {
    cout << 1 + 2 * (abs(t1 * a1 - t1 * b1) / abs((t1 * a1 + t2 * a2) - (t1 * b1 + t2 * b2)))
      - (abs(t1 * a1 - t1 * b1) % abs((t1 * a1 + t2 * a2) - (t1 * b1 + t2 * b2)) == 0);
  }
}
