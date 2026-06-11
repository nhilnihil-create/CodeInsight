#include <iostream>
#include <string>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int cnt = 0;
  for (int i = 0; i <=n-3; ++i) {
    if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ++cnt; 
  }
  std::cout << cnt << std::endl;
  
  return 0;
}