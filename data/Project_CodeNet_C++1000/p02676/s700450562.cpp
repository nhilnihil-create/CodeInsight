#include<iostream>
#include<string>

int main(){
  int N;
  std::string S;
  std::cin >> N;
  std::cin >> S;
  
  if (N >= S.length()) std::cout << S;
  else {
    for (int i = 0; i < N ; i++) std::cout << S[i];
    std::cout << "...";
  }
  return 0;
}