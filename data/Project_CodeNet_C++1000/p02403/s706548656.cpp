#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int H, W;
  for (;;) {
    cin >> H >> W;
    if (!H && !W)
      break;

    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j)
        printf("#");
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}