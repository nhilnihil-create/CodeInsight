#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t H, W;
  cin >> H >> W;

  if (H == 1 || W == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (H % 2 == 0 || W % 2 == 0) {
    cout << W * H / 2 << endl;
    return 0;
  } else {
    cout << W * (H - 1) / 2 + (W + 1) / 2 << endl;
    return 0;
  }
}