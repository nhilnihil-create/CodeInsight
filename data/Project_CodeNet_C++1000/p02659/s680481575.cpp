#include <iostream>
#include <cmath>
int main(){
  unsigned long long A;
  std::cin >> A;
  double B;
  std::cin >> B;
  int C = std::round(B * 100);

  unsigned long long mult;

  mult = A * C / 100;
 
  std::cout << mult;
  
  return 0;
}
