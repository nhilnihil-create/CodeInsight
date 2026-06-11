#include <iostream>
#include <string>

int main(){
  std::string S, T;
  std::cin >> S >> T;
  if (S.size() + 1 == T.size()){
    T.pop_back();
    if (S == T){
      std::cout << "Yes";
      return 0;
    }
  }
  std::cout << "No";
  return 0;
}