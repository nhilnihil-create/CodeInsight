#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x;
  cin >> x;

  rep(i, 5) {
    int o100 = x / 100, u100 = x % 100;
    // cerr << i << " " << o100 << " " << u100 << endl;
    int num = min(o100, u100 / (5 - i));
    // cerr << i << 'b' << endl;
    x -= (105 - i) * num;
    // cerr << i << 'c' << endl;
  }
  if (x % 100 == 0)
    cout << '1' << endl;
  else
    cout << '0' << endl;
  return 0;
}
