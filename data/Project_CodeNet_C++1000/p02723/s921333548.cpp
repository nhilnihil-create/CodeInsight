#include <bits/stdc++.h>

int main(void)
{
  std::string s;
  std::cin >> s;

  bool flag = false;

  if (s[2] == s[3]) {
    if (s[4] == s[5]) {
      flag = true;
    }
  }

  if (flag) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
}