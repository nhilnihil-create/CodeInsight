#include <iostream>

using namespace std;

int main() {
  int H, W, s[100][100], r[100][100];
  char c;
  cin >> H >> W;
  for (int i = 0; i != H; i++)
    for (int j = 0; j != W; j++) {
      cin >> c;
      s[i][j] = (c == '#');
      if (!i && !j) r[i][j] = s[i][j];
      else {
        int p = j ? r[i][j - 1] + (s[i][j] > s[i][j - 1]) : 200;
        int q = i ? r[i - 1][j] + (s[i][j] > s[i - 1][j]) : 200;
        r[i][j] = min(p, q);
      }
    }

  cout << r[H - 1][W - 1] << endl;
}
