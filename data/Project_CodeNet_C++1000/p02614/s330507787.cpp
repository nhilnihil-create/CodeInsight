#include <iostream>
#include <string>

int H, W, K;

std::string grid[7];

int main() {
  std::cin >> H >> W >> K;
  for (int i = 0; i < H; ++i)
    std::cin >> grid[i];

  int ans = 0;
  for (int mask = 0; mask < (1 << (H+W)); ++mask) {
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if ((1 << i) & mask)  continue;
        if ((1 << (j + H)) & mask)  continue;
        if (grid[i][j] == '#')
          cnt++;
      }
    }
    if (cnt == K)
      ans++;
  }

  std::cout << ans << "\n";

  return 0;
}
