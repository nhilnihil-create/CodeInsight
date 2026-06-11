#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; ++i)
    std::cin >> s[i];

  std::map<std::string, int> mp;
  for (int i = 0; i < n; ++i)
    mp[s[i]] += 1;

  int res = 0;
  for (auto &kv: mp)
    res += 1;

  std::cout << res << std::endl;
}
