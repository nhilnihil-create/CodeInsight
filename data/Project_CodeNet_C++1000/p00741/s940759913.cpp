#include <iostream>
using namespace std;

constexpr int MAX_H = 55;
constexpr int MAX_W = 55;

int H, W;
int grid[MAX_H][MAX_W];
bool reached[MAX_H][MAX_W];

int dh[8] = {-1, -1, -1,  0,  0,  1,  1,  1};
int dw[8] = {-1,  0,  1, -1,  1, -1,  0,  1};

void dfs(int h, int w) {
  reached[h][w] = true;
  for (int i{}; i < 8; ++i) {
    int nh = h + dh[i];
    int nw = w + dw[i];
    if (nh < 0 || nh >= H || nw < 0 || nw >= W ||
        reached[nh][nw] || grid[nh][nw] == 0)
      continue;
    dfs(nh, nw);
  }
}

int main() {
  while (true) {
    scanf("%d%d", &W, &H);
    if (W == 0 && H == 0) break;
    for (int h{}; h < H; ++h) {
      for (int w{}; w < W; ++w) {
        reached[h][w] = false;
        scanf("%d", &grid[h][w]);
      }
    }

    int island{};
    for (int h{}; h < H; ++h) {
      for (int w{}; w < W; ++w) {
        if (grid[h][w] == 0 || reached[h][w])
          continue;
        dfs(h, w);
        ++island;
      }
    }

    printf("%d\n", island);
  }

  return 0;
}

