#include <algorithm>
#include <iostream>
#include <vector>

void dfs(uint32_t N, std::string str = "", uint32_t last = 0) {
  if (str.size() == N) {
    std::cout << str << std::endl;
    return;
  }

  for (uint32_t i = 0; i <= last; i++)
    dfs(N, str + static_cast<char>('a' + i), std::max(i + 1, last));

  return;
}

int main() {
  uint32_t N = 0;
  std::cin >> N;

  dfs(N);

  return 0;
}