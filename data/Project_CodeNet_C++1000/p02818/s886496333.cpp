#include <iostream>

int main() {
  long long a, b, k;
  std::cin >> a >> b >> k;
  if (a <= k) {
    k -= a;
    a = 0;
    b = std::max(0LL, b-k);
  } else {
    a -= k;
  }
  std::cout << a << " " << b << std::endl;
  
  return 0;
} 