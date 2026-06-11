#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
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
