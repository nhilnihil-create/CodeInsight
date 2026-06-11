#include <iostream>
#include <string>

int main()
{
  std::string S;
  std::cin >> S;
  bool res = true;
  for (int i=0; i<3; i++) {
    if (S[i] == S[i+1]) { res = false; break; }
  }
  if (res) std::cout << "Good" << std::endl;
  else std::cout << "Bad" << std::endl;
  return 0;
}