#include <iostream>

int main(){
  int N;
  std::cin >> N;
  if (N % 10 == 3) std::cout << "bon";
  else if (N % 10 == 0 || N % 10 == 1 || N % 10 == 6 || N % 10 == 8) std::cout << "pon";
  else std::cout << "hon";
  return 0;
}