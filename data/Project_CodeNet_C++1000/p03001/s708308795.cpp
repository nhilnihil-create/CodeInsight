#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll W, H, x, y;
  cin >> W >> H >> x >> y;
  cout << W*H/2.0 << " ";
  if (W/2.0 == x && H/2.0 == y) cout << 1 << endl;
  else cout << 0 << endl;
}
