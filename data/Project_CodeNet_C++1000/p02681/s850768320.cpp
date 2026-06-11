#include<bits/stdc++.h>

int main(void)
{
  std::string s, t;
  std::cin >> s >> t;

  if (s == t.substr(0, s.size())) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
}