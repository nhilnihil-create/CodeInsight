#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int H, W;
  for (;;) {
    cin >> H >> W;
    if (H == 0 && W == 0) {
      break;
    }
    for (int h = 0; h < H; ++h) {
      for (int w = 0; w < W; ++w) {
        if (w > 0 && w < W - 1 && h > 0 && h < H - 1) {
          cout << ".";
        } else {
          cout << "#";
        }
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}