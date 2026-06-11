#include <iostream>

int main(int argc, char const *argv[]) {
  char c[2] = {'#','.'};
  while(1){
    int height=0,width=0;
    std::cin >> height >> width;
    if((height==0)&&(width==0))break;
    for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
        std::cout << c[(i+j)%2];
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}