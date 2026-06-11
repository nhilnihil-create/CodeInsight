#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int c_count = 0;
  for (int i = 0; i < s.size(); ++i) {
    c_count += (s[i] == t[i]);
  }
  int ans = s.size() - c_count;
  std::cout << ans << std::endl;
  
  return 0;
}