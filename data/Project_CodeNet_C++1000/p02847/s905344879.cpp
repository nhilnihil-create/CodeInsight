#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> s = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  std::string d; std::cin >> d;
  int ans;
  for (int i = 0; i < 7; ++i) {
    if (s[i] == d) ans = 7-i;
  }
  std::cout << ans << std::endl;
  
  return 0;
}