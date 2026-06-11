#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t H, W; cin >> H >> W;
  
  if (H == 1 || W == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  if (H * W % 2 == 0) cout << H * W / 2 << endl;
  
  else cout << H * W / 2 + 1 << endl;
  
}