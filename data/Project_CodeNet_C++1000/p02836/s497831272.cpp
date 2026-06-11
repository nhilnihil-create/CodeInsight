#include <iostream>
#include <string>

int main() {
  std::string s; std::cin >> s;
  int ans = 0;
  int l = s.size();
  for (int i = 0; i < l/2; ++i) {
    if (s[i] == s[l-1-i]) continue;
    ++ans;
  }
  std::cout << ans << std::endl;
  
  return 0;
}