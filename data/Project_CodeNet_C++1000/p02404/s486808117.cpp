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
      const bool is_boundary = i == 0 || i == H - 1;                                                                                                                      
      for (int j = 0; j < W; ++j) {
        if (!is_boundary && j > 0 && j < W - 1)                                                                                                                           
          printf(".");
        else
          printf("#");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}