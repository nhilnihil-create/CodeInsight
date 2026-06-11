#include <ios>
#include <iostream>
#include <vector>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];

  int m = 1;
  for (int i = 0; i < n; ++i)
    m = lcm(m, a[i]);

  int c = 0;
  for (int i = 0; i < n; ++i)
    c += m / a[i];

  std::cout << std::fixed << double(m) / c << std::endl;
}
