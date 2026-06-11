#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  for (int i = 0; i < H; i++) {
    if (i < B) {
      for (int j = 0; j < W; j++) {
        if (j < A) cout << 0;
        else cout << 1;
      }
    }
    else {
      for (int j = 0; j < W; j++) {
        if (j < A) cout << 1;
        else cout << 0;
      }
    }
    cout << endl;
  }
}