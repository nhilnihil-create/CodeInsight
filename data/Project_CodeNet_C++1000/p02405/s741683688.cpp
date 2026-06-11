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
        if (h % 2 == 0) {
          if (w % 2 == 0) {
            cout << "#";
          } else {
            cout << ".";
          }
        } else {
          if (w % 2 == 0) {
            cout << ".";
          } else {
            cout << "#";
          }
        }
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}