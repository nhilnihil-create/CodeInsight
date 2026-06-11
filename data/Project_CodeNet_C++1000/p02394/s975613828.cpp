#include <iostream>
int main(){
 int w;
 int h;
 int x;
 int y;
 int r;
 std::cin >> w >> h >> x >> y >> r;
 if( w-r >= x && h-r >= y && x >=1 && y >= 1){
  std::cout << "Yes" << std::endl;
 } else {
  std::cout << "No" << std::endl;
 }
}