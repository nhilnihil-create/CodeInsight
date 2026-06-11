#include <iostream>

int main(){
  int a,b; std::cin >> a >> b;
  int c = [a,b] () -> int { return a*b; }();
  int d = [a,b] () -> int { return 2*(a+b); }();
  std::cout << c << " " << d << std::endl;
  return 0;
}