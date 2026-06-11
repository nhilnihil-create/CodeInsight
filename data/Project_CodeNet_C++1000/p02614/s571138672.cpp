#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;

  vector<vector<int>> c(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char ch;
      cin >> ch;
      c[i][j] = ch == '.' ? 0 : 1;
    }
  }

  int comb = 0;
  for (int bit = 0; bit < (1 << h); ++bit) {
    for (int bjt = 0; bjt < (1 << w); ++bjt) {
      int cnt = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (bit & (1 << i) || bjt & (1 << j)) continue;
          if (c[i][j]) cnt++;
        }
      }
      if (cnt == k) comb++;
    }
  }

  cout << comb << endl;
}
