#include <iostream>

int main() {
  int n; std::cin >> n;
  long long sum = ((1LL + n) * n) / 2;
  int c3 = n / 3;
  int c5 = n / 5;
  int c15 = n / 15;
  sum -= (((1LL + c3) * c3) / 2 * 3);
  sum -= (((1LL + c5) * c5) / 2 * 5);
  sum += (((1LL + c15) * c15) / 2 * 15);
  std::cout << sum << std::endl;
  
  return 0;
}