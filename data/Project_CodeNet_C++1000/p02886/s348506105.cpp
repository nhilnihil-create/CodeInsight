#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> d(n);
  for (int i = 0; i < n; ++i)
    std::cin >> d[i];
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      ans += d[i] * d[j];

  std::cout << ans << std::endl;
}
