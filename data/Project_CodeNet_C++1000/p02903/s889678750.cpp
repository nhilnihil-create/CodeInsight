#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  int x = 0, y = 1;
  for (int i = 0; i < h; ++i) {
    if (i == b)
      swap(x, y);
    for (int j = 0; j < w; ++j) {
      cout << (j < a ? x : y);
    }
    cout << endl;
  }
}