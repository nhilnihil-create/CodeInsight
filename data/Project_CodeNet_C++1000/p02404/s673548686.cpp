#include <iostream>
using namespace std;

int main() {
  int H,W;
  while (cin >> H >> W, H!=0 || W!=0) {
    for (int i = 0; i < W; i++) {
      cout << "#";
    }
    cout << endl;
    for (int j = 0; j < H - 2; j++) {
      cout << "#";
      for (int k = 0; k < W - 2; k++) {
        cout << ".";
      }
      cout << "#" << endl;
    }
    for (int i = 0; i < W; i++) {
      cout << "#";
    }
    cout << endl << endl;
  }
  return 0;
}