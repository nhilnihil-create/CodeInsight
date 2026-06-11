#include <iostream>

typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;  std::cin >> N;
  std::cout << (1000 - (N % 1000)) % 1000 << "\n";
  

  return 0;
}
