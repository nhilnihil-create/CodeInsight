#include<iostream>
int main () {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << (((a + b + c) <= 21) ? "win" : "bust") << std::endl;
}