#include <iostream>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int H = 0,W = 0;
  std::cin >> H >> W;
  while(H != 0 && W != 0) {
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        printf("#");
      }
      printf("\n");
    }
    printf("\n");
    std::cin >> H >> W;
  } 
  return 0;
}