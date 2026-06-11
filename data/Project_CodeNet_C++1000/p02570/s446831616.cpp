#include<string>
#include<iostream>

int main(){
  float D, T, S;
  std::cin >> D >> T >> S;
  float time = D/S;
  if(time<=T){
    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }
  return 0;
}