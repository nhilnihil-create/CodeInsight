#include <iostream>

template<class T> T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  long long a, b; std::cin >> a >> b;
  long long g = gcd(a, b);
  long long ans = a * b / g;
  std::cout << ans << std::endl;
  
  return 0;
}