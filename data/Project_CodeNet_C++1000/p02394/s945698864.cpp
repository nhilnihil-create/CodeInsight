#include <iostream>
using namespace std;
int main() {
  signed int x, y;
  unsigned int W, H, r, hantei;
  cin >> W >> H >> x >> y >> r;
  signed int top = y + r;
  signed int right = x + r;
  signed int bottom = y - r;
  signed int left = x - r;

  if(top > H || right > W || bottom < 0 || left < 0){
    cout << "No\n";
  } else{
    cout << "Yes\n";
  }
}