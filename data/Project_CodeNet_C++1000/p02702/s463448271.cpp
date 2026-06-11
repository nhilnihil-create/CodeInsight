#include <iostream>
#include <map>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;

  int n = s.size();

  // t[i] := s[i, n) mod 2019
  int pow = 1;
  std::vector<int> t(n + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    t[i] = (pow * (s[i] - '0') + t[i + 1]) % 2019;
    pow = (10 * pow) % 2019;
  }

  std::map<int, int> mp;
  for (int i = 0; i <= n; ++i)
    mp[t[i]] += 1;

  int res = 0;
  for (auto &kv : mp)
    res += kv.second * (kv.second - 1) / 2;

  std::cout << res << std::endl;
}
