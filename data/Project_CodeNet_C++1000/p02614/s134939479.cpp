#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int h, w, k;

int solve(int x, int y, vector<vector<char>> field) {
  if (y == h) {
    int count = 0;
    rep(i, w) rep(j, h) {
      if (field[i][j] == '#') count++;
    }
    return count == k ? 1 : 0;
  }
  if (x == w) {
    int tmp = solve(x, y + 1, field);
    rep(i, w) field[i][y] = 'r';
    return tmp + solve(x, y + 1, field);
  }
  int tmp = solve(x + 1, y, field);
  rep(i, h) field[x][i] = 'r';
  return tmp + solve(x + 1, y, field);
}

int main() {
  cin >> h >> w >> k;
  vector<vector<char>> field(w, vector<char>(h));
  rep(y, h) rep(x, w) cin >> field[x][y];
  cout << solve(0, 0, field) << endl;
  return 0;
}