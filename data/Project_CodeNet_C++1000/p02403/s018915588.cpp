#include <iostream>
using namespace	std;

int main() {
  int H, W;
  bool loop = true;
  while (loop) {
    cin >> H >> W;
    if ((H == 0) && (W == 0)) {
      loop = false;
      continue;
    }
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cout << "#";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}