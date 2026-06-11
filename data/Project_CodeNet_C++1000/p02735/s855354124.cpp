#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Cell {
  int x;
  int y;
  int cost;
};

bool operator<(const Cell &lhs, const Cell &rhs) { return lhs.cost < rhs.cost; }
bool operator>(const Cell &lhs, const Cell &rhs) { return lhs.cost > rhs.cost; }

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> map(H + 1, vector<char>(W + 1));
  vector<vector<int>> cost(H + 1, vector<int>(W + 1, -1));

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      char cell;
      cin >> cell;
      map[i][j] = cell;
    }
  }

  std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> queue;
  int init_cost = (map[1][1] == '.') ? 0 : 1;
  queue.push({1, 1, init_cost});

  while (!queue.empty()) {
    auto cell = queue.top();
    queue.pop();
    int x = cell.x;
    int y = cell.y;

    if (x < W && cost[y][x + 1] == -1) {
      int move_cost = (map[y][x] == map[y][x + 1]) ? 0 : 1;
      cost[y][x + 1] = cell.cost + move_cost;
      queue.push({x + 1, y, cost[y][x + 1]});
    }
    if (y < H && cost[y + 1][x] == -1) {
      int move_cost = (map[y][x] == map[y + 1][x]) ? 0 : 1;
      cost[y + 1][x] = cell.cost + move_cost;
      queue.push({x, y + 1, cost[y + 1][x]});
    }
  }
  int ans = cost[H][W];
  if (map[H][W] == '#') ans++;
  cout << ans / 2 << endl;
}
