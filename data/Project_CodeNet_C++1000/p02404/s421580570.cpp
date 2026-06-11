#include <bits/stdc++.h>
using namespace std;

int main() {
  while(1) {
    int H,W;
    cin >> H >> W;

    if(H == 0 && W == 0) break;
    for(int a = 0; a < W; a++) {
      printf("#");
    }
    printf("\n");

    for(int b=0+1;b<H-1; b++){
      printf("#");
      for(int c=0+1;c<W-1;c++){
          printf(".");
      }
      printf("#");
      printf("\n");
    }

    for(int d = 0; d < W; d++) {
      printf("#");
    }
    printf("\n");
    printf("\n");
  }

  return 0;
}