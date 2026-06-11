#include <algorithm>
#include <bitset>
#include <boost/rational.hpp>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  rep(i, H) {
    cin >> grid[i];
    grid[i].push_back('?');
  }
  grid.push_back(string(W + 1, '?'));

  const int INF = H * W;
  vector<vector<int>> dist(H + 1, vector<int>(W + 1, INF));
  dist[0][0] = 0;
  rep(i, H) rep(j, W) {
    chmin(dist[i][j + 1], dist[i][j] + (grid[i][j] != grid[i][j + 1]));
    chmin(dist[i + 1][j], dist[i][j] + (grid[i][j] != grid[i + 1][j]));
  }

  int result =
      dist[H - 1][W - 1] + (grid[0][0] == '#') + (grid[H - 1][W - 1] == '#');
  cout << (result + 1) / 2 << endl;
  return 0;
}
