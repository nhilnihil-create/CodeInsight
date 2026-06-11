#include<iostream>

template<typename T>
T input(){
  T t;
  std::cin >> t;
  return t;
}

int main(){
  while(true){
    const auto H = input<int>();
    const auto W = input<int>();
    if(H == 0 && W == 0)
      return 0;
    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j)
        std::cout << ((i + j) % 2 == 0 ? '#' : '.');
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}