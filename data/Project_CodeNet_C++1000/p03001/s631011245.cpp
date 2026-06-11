#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t W, H, x, y;
  cin >> W >> H >> x >> y;
  cout << (W * H + 0.0) / 2 << " ";
  if ((W + 0.0) / 2 == x && (H + 0.0) / 2 == y) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }
}