#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  std::cin >> n;
  if (n%10 == 3) {
    std::cout << "bon" << std::endl;
  }
  else if (n%10 == 0 || n%10 == 1 || n%10 == 6 || n%10 == 8) {
    std::cout << "pon" << std::endl;
  }
  else {
    std::cout << "hon" << std::endl;
  }
}