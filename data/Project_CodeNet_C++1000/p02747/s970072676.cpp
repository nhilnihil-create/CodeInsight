#include <string>
#include <iostream>

int main(){
  std::string hitachi;
  std::cin >> hitachi;
  std::string type_hitachi;
  for(int i = 0; i < hitachi.size()/2; ++i){
    type_hitachi += "hi";
  }
  if(hitachi == type_hitachi){
    std::cout << "Yes" << std::endl;
  }else{
    std::cout << "No" << std::endl;
  }
  return 0;
}