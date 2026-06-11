#include <iostream>
#include <vector>

int main() {
  int n, k; std::cin >> n >> k;
  std::vector<bool> hasTreat(n, false);
  
  while (k--) {
    int c; std::cin >> c;
	while (c--) {
      int s; std::cin >> s;
      --s;
      hasTreat[s] = true;
    }
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += (hasTreat[i] == false); 
  }
  std::cout << sum << std::endl;
  return 0;
}