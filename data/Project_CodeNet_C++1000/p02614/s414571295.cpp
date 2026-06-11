#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

/*
The patterns to paint 0 to h rows can be represented by 2^h where the options are yes or no, or 0 or 1.
Take an example when h = 2, there are 2^2=4 patterns of painting: 00, 01, 10, 11 or paint no row, paint second row,
paint first row, paint both rows, respectively.
Same for columns. Thus, there are 2^(h+w) patterns of painting.
For all patterns, check the color of the remaining squares. If the number of black squares == k among them,
count that pattern in.
*/

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<char>> grid(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> grid[i][j];

  int count = 0;  // number of patterns that result in exactly k black squares remaining
  rep(pi, 1<<h) rep(pj, 1<<w) {  // for all patterns. pi -> patterns for row. pj -> patterns for column
    int black = 0;
    rep(i, h) rep(j, w) {
      // i-th digit of pi == 1 means that row is all red
      // j-th digit of pj == 1 means that column is all red
      // check color of grid[i][j] that is remaining not red
      if (((pi>>i) & 1) == 0 && ((pj>>j) & 1) == 0 && grid[i][j] == '#') black++;
    }
    if (black == k) count++;  // k black squares are remaining after the operation
  }

  cout << count << endl;
}