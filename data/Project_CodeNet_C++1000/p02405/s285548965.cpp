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
      const char c = i % 2 == 0 ? '#' : '.';
      const char d = c == '#' ? '.' : '#';
      for (int j = 0; j < W; ++j) {
        if (j % 2 == 1)
          printf("%c", d);
        else
          printf("%c", c);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}