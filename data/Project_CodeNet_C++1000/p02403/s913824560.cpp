#include <iostream>
#include <string>

using namespace std;

int H, W;
string a[301][301];

int main() {
  while(1){
    cin >> H >> W;
    if(H == 0 && W == 0) break;
    for(int i = 0; i < H*W; i++){
      int x = i%W;
      int y = i/W;
      a[y][x] = "#";
      cout << a[y][x];
      if(x == W-1) cout << endl;
    }
    cout << endl;
  }
}