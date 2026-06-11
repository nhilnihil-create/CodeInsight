#include <iostream>

int main(void){
  int a, b;
  std::cin >> a >> b;
  if(b==1) std::cout << 0 << std::endl;
  else     std::cout << a-b << std::endl;
  return 0;
}