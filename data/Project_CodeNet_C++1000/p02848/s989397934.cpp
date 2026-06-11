#include <iostream>
#include <string>

int main() {
  int n;
  std::string s, s_shift = "";
  std::cin >> n >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (isupper(s[i])) {
      s_shift += char(int(s[i]+n-65)%26+65); 
    }
    else {
      s_shift += char(int(s[i]+n-96)%26+96);
    } 
  }
  std::cout << s_shift; 
}