#include <iostream>

int main() {
  int n, m; std::cin >> n >> m;
  int sum = 0;
  sum += (n*(n-1))/2;
  sum += (m*(m-1))/2;
  std::cout << sum << std::endl;
  
  return 0;
}
