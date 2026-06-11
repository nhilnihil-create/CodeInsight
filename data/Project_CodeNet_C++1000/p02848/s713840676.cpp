#include <iostream>

char rot_n(char c, int n) {
  char cc = c + n;
  if (cc > 'Z')
    return cc - 26;
  return cc;
}

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  for (auto c : s)  {
    std::cout << rot_n(c, n);
  }
  std::cout << std::endl;
}
