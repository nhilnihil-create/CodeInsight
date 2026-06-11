#include <bits/stdc++.h>
using namespace std;

int H,W;
int b = 1;

int main() {
  while(1) {
    b = 1;
    cin >> W >> H;
    if ( H == 0 && W == 0) {
      break;
    }
    for (int a = -1; a < H;) {
      ++a;
      if( a == H && b < W) {
        cout << endl;
        a = 0;
        b = b + 1;
      }else if ( a == H && b == W) {
        cout << endl << endl; // Two times new line.
        break;
      }
      cout << "#";
    }
  }
}