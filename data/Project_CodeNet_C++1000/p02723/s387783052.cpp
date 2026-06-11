#include <iostream>
#include <string>

int main(){
  std::string S;
  std::cin >> S;
  std::cout << (S[2]==S[3] && S[4]==S[5] ? "Yes" : "No");
  return 0;
}