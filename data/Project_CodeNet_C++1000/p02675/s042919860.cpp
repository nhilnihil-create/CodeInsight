#include<bits/stdc++.h>

int main(void)
{
  std::string num;
  std::cin >> num;

  int end = num.size()-1;
  int endnum = num[end] - '0';

  if (endnum == 3) {
    std::cout << "bon\n";
  }
  else if (endnum == 0 || endnum == 1 | endnum == 6 | endnum == 8) {
    std::cout << "pon\n";
  }
  else {
    std::cout << "hon\n";
  }
}