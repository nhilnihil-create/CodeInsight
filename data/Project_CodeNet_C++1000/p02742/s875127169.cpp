#include <bits/stdc++.h>

using namespace std;

int main() {
  uint64_t H, W;
  
  cin >> H >> W;
  
  if (W == 1 || H == 1) {
    cout << 1 << endl;
  } else {
    cout << (H % 2 == 0 || W % 2 == 0 ? H * W / 2 : (H * W - 1) / 2 + 1) << endl;
  }
  
  return 0;
}
