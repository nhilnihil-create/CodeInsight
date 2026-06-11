#include <iostream>
#include <string>

int main() {
  int c = 0;
  std::string s1, s2;
  std::cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] != s2[i]) {
      c++;
    }
  }
  std::cout << c;
}