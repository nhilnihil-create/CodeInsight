#include <iostream>
#include <string>

int main(){
  std::string S;
  std::cin >> S;
  
  char hi[] = {'h','i'};
  
  if (S.size() % 2){
    std::cout << "No" << std::endl;
    return 0;
  }
  
  for(auto i=0; i < S.size(); ++i){
    if(S[i] != hi[i%2]){
      std::cout << "No" << std::endl;
      return 0;
    }
  }
 
  std::cout << "Yes" << std::endl;
  return 0;
}