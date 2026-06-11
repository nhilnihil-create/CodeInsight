// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  if (A == 0 && B == 0) {
    for (int j = 0; j < H; j++) {
      for (int i = 0; i < W; i++) {
        cout << 0;
      }
      cout << endl;
    }
    return 0;
  }
  if (A == 0) {
    for (int j = 0; j < B; j++) {
      for (int i = 0; i < W; i++) {
        cout << 1;
      }
      cout << endl;
    }
    for (int j = B; j < H; j++) {
      for (int i = 0; i < W; i++) {
        cout << 0;
      }
      cout << endl;
    }
    return 0;
  }
  if (B == 0) {
    for (int j = 0; j < H; j++) {
      for (int i = 0; i < A; i++) {
        cout << 1;
      }
      for (int i = A; i < W; i++) {
        cout << 0;
      }
      cout << endl;
    }
    return 0;
  }
  vector<vector<int>> ans(H, vector<int>(W));
  for (int i = 0; i < H - B; i++) {
    for (int j = 0; j < W - A; j++) {
      ans[i][j] = 1;
    }
  }
  for (int i = H - B; i < H; i++) {
    for (int j = W - A; j < W; j++) {
      ans[i][j] = 1;
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
