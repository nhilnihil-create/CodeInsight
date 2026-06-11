#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  for (int i = 0; i < H; i ++) {
    for (int j = 0; j < W; j++) {
      if (i < B && j < A) cout << 0;
      else if (B <= i && A <= j) cout << 0;
      else cout << 1;
      if (j == W-1) cout << endl;
    }
  }
}
