#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int H, W;
  while (true) {
    cin >> H >> W;
    if (H == 0 && W == 0) return 0;
    for (int h = H; h > 0; h--) {
      for (int w = W; w > 0; w--) {
        cout << '#';
      }
      cout << endl;
    }
    cout << endl;
  }
}