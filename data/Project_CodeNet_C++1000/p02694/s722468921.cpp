#include <iostream>

int main() {
  
  long long b = 100, n, k=0;
  std::cin >> n;
  while (b < n) {
    b += b/100;
    k++;
  }
  std::cout << k;
}