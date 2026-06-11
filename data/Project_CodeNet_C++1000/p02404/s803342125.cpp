#include <iostream>
using namespace std;

int main()
{
  int H, W;
  while(true) {
    cin >> H >> W;
    if (H == 0 && W == 0) {
      break;
    }
    for(int j = 0; j < W; j++) {
        cout << '#';
    }
    cout <<  endl;
    for(int i = 1; i < H-1; i++) {
      cout << '#';
      for(int j = 1; j < W-1; j++) {
        cout << '.';
      }
      cout << '#' << endl;
    }
    for(int j = 0; j < W; j++) {
      cout << '#';
    }
    cout << endl << endl;
  }
}
