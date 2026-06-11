#include <iostream>

int main() {
  int input_a, input_b;
  std::cin >> input_a >> input_b;
  if (input_a < input_b) std::cout << "a < b" << std::endl;
  else if (input_a > input_b) std::cout << "a > b" << std:: endl;
  else std::cout << "a == b" << std::endl;
  return 0;
}