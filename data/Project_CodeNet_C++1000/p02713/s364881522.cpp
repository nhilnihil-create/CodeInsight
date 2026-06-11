#include <iostream>

int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

int main() {
  int K;
  std::cin >> K;

  long long res = 0;
  for (int a = 1; a <= K; ++a) {
    for (int b = 1; b <= K; ++b) {
      for (int c = 1; c <= K; ++c) {
        res += gcd(gcd(a, b), c);
      }
    }
  }
  std::cout << res << std::endl;
}
