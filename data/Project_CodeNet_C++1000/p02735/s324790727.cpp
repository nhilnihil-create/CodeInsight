#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> m(h);
  for (int i = 0; i < h; i++) cin >> m[i];
  vector<vector<int>> a(h, vector<int>(w));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i == 0 && j == 0) {
        if (m[i][j] == '#') a[0][0] = 1;
      }
      else if (i == 0) {
        a[i][j] = a[i][j - 1];
        if (m[i][j] != m[i][j - 1]) a[i][j]++;
      }
      else if (j == 0) {
        a[i][j] = a[i - 1][j];
        if (m[i][j] != m[i - 1][j]) a[i][j]++;
      }
      else{
        int add1 = 0, add2 = 0;
        if (m[i][j] != m[i][j - 1]) add1++;
        if (m[i][j] != m[i - 1][j]) add2++;

        a[i][j] = min(a[i][j-1] + add1, a[i - 1][j] + add2);
      }

    }
  }

  cout << (a[h - 1][w - 1] + 1) / 2 << endl;

  return 0;
}