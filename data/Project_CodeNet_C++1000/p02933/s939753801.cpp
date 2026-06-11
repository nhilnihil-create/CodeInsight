#include <iostream>
#include <string>

int main(){
  int a = 0;
  std::string s = "";
  std::cin >> a;
  std::cin >> s;
  
  if(a >= 3200){
  	std::cout << s;
  }else{
    std::cout << "red";
  }
  std::cout << '\n';
  
  return 0;
}