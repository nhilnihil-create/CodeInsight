#include <iostream>

using namespace std;

int main(void) {
  int H, W;
  while(cin >> H >> W && H && W) {
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W && (i == 0 || i == H - 1); j++) {
        cout << "#";
      }
      for(int k = 0; k < 1 && (i && i != H - 1); k++) {
        cout << "#";
      }
      for(int l = 0; l < W - 2 && (i && i != H - 1); l++) {
        cout << ".";
      }
      for(int m = 0; m < 1 && (i && i != H - 1); m++) {
        cout << "#";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}