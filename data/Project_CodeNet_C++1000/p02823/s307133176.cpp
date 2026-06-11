#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  ll n, a, b;
  std::cin >> n >> a >> b;
  if(b < a)
    std::swap(a, b);
  if(a % 2 == b % 2)
    std::cout << (b - a) / 2;
  else { 
    std::cout << std::min(a - 1 + b, 2 * n - a - b + 1) / 2;
  }
  return 0;
}
