#include <iostream>
#include <vector>

int main() {
  int n; std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i]; 
    if (a[i] == 0) {
      std::cout << 0 << std::endl;
      return 0;
    }
  }
  long long ms = 1e18;
  long long m = 1;

  for (int i = 0; i < n; ++i) {

    if (ms / m < a[i]) {
      std::cout << -1 << std::endl;
      return 0;
    }
    m *= a[i];
    
  }

  std::cout << m << std::endl;

  return 0;
}
