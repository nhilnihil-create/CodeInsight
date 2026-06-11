#include <bits/stdc++.h>

int main(void)
{
  std::string n;
  std::cin >> n;

  bool flag = false;

  for (int i = 0; i < n.size(); i++) {
    if (n[i] == '7') {
      flag = true;
      break;
    }
  }
  
  if (flag) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
}