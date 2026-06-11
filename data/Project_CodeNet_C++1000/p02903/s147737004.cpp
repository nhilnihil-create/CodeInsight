#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  int n, m, a, b;
  std::cin >> n >> m >> a >> b;
  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= m; j++)
      std::cout << ((i <= b) ^ (j <= a));
    std::cout << '\n';
  }
}
