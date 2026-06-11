#include<iostream>
int main(){
  int i,j,h,w;
  while(1){
    std::cin >> h >> w;
    if(h == 0 && w == 0) return 0;
    for(i=0; i<h; i++){
      for(j=0; j<w; j++){
        bool flag = (i == 0 || i == h - 1 ) || ( j == 0 || j == w - 1);
        std::cout << (flag ? "#" : ".");
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}