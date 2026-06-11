#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  double a, b;
  cin >> a >> b;

  int cand = (int)floor(a / 8 * 100);
  double last = b * 10 + 9;

  if (floor(cand * 0.08) == a && floor(cand * 0.1) == b) {
    cout << cand << endl;
    return 0;
  }

  while (cand < last) {
    cand++;

    if (floor(cand * 0.08) == a && floor(cand * 0.1) == b) {
      cout << cand << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
