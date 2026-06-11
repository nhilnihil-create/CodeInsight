#include <iostream>
using namespace std;

char chess(int h, int w) {
  if((h+w)%2==0) {
    return '#';
  }
  return '.';
}

int main()
{
  int H, W;
  while(true) {
    cin >> H >> W;
    if (H == 0 && W == 0) {
      break;
    }
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        cout << chess(i,j);
      }
      cout << endl;
    }
    cout << endl;
  }
}

