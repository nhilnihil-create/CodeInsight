#include <iostream>
using namespace std;

int main() {
  int H, W;
  while (true) {
    cin >> H >> W;
    if (H == 0 && W == 0) return 0;
    for (int h = 0; h < H; h++) {
      for (int w = 0; w < W; w++) {
        if ((h + w) % 2 == 0) cout << '#';
        else cout << '.';
      }
      cout << endl;
    }
    cout << endl;
  }
}