#include <iostream>

int n;

int main() {
	std::cin >> n;
  	int t = n % 10;
  	if (t == 2 || t == 4 || t == 5 || t == 7 || t == 9) {
      std::cout << "hon";
    }
  	else if (t == 0 || t == 1 || t == 6 || t == 8) {
      std::cout << "pon";
    }
  	else {
      std::cout << "bon";
    }
  std::cout << std::endl;
  return 0;
}