#include <iostream>

using namespace std;

bool grid[2000][2000];
int l[2000][2000];
int r[2000][2000];
int u[2000][2000];
int b[2000][2000];

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char tmp; cin >> tmp;
      grid[i][j] = tmp == '.';
      
      if (!grid[i][j]) {
        l[i][j] = 0;
        r[i][j] = 0;
        u[i][j] = 0;
        b[i][j] = 0;
        continue;
      }

      if (j == 0) {
        l[i][j] = 1;
      } else {
        l[i][j] = l[i][j-1]+1;
      }
      
      if (i == 0) {
        u[i][j] = 1;
      } else {
        u[i][j] = u[i-1][j]+1;
      }
    }
    for (int j = W-1; j >= 0; j--) {
      if (!grid[i][j]) continue;
      if (j == W-1) {
        r[i][j] = 1;
      } else {
        r[i][j] = r[i][j+1]+1;
      }
    }
  }
  for (int j = 0; j < W; j++) {
    for (int i = H-1; i >= 0; i--) {
      if (!grid[i][j]) continue;
      if (i == H-1) {
        b[i][j] = 1;
      } else {
        b[i][j] = b[i+1][j]+1;
      }
    }
  }
  int mx = -10000;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int sum = u[i][j] + r[i][j] + l[i][j] + b[i][j] - 3;
      mx = mx > sum ? mx : sum;
    }
  }
  cout << mx << endl;
  return 0;
}