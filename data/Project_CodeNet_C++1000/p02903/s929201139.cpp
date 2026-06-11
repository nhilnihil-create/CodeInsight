#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  int x = 0, y = 1;
  vector<vector<int>> v(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    if (i == b)
      swap(x, y);
    for (int j = 0; j < w; ++j) {
      if (j < a)
        v[i][j] = x;
      else
        v[i][j] = y;
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << v[i][j];
    }
    cout << endl;
  }
}