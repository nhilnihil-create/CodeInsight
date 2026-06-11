#include <iostream>

typedef long long ll;

int main(){
  ll A;
  double B;
  std::cin >> A >> B;
  ll B100 = B * 100;
  ll resa = A * B100;
  std::cout << resa / 100 << std::endl;
  return 0;
}