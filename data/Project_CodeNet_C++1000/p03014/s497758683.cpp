#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int h, w, ans;
string s[2200];
int a[2200][2200][4];

void dfs() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') continue;
      if (j == 0) {
        a[i][j][0] = 1;
      } else {
        a[i][j][0] = a[i][j-1][0] + 1;
      }
    }
  }
  
  for (int i = 0; i < h; i++) {
    for (int j = w-1; j >= 0; j--) {
      if (s[i][j] == '#') continue;
      if (j == w-1) {
        a[i][j][1] = 1;
      } else {
        a[i][j][1] = a[i][j+1][1] + 1;
      }
    }
  }
  
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (s[j][i] == '#') continue;
      if (j == 0) {
        a[j][i][2] = 1;
      } else {
        a[j][i][2] = a[j-1][i][2] + 1;
      }
    }
  }
  
  for (int i = 0; i < w; i++) {
    for (int j = h-1; j >= 0; j--) {
      if (s[j][i] == '#') continue;
      if (j == h-1) {
        a[j][i][3] = 1;
      } else {
        a[j][i][3] = a[j+1][i][3] + 1;
      }
    }
  }
}

int main() {
  cin >> h >> w;
  
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  
  dfs();
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int sum = 0;
      for (int k = 0; k < 4; k++) {
        sum += a[i][j][k];
      }
      sum -= 3;
      ans = max(ans, sum);
    }
  }
  
  cout << ans << endl;
  return 0;
}
