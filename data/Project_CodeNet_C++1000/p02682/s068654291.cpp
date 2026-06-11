#include <iostream>

int main(){
  long A, B, C, K;
  std::cin >> A >> B >> C >> K;
  
  if (K <= A) std::cout << K;
  else if (K <= A + B) std::cout << A;
  else std::cout << A - (K - A - B);
  
  return 0;
}