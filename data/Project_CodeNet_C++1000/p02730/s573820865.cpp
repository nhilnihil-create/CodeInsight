#include <iostream>
#include <string>

bool isPal(std::string S)
{
  int L = S.length();
  for (int i=0; i<L/2; i++) {
    if (S[i] != S[L-1-i]) return false;
  }
  return true;
}

int main()
{
  std::string S;
  std::cin >> S;
  int L = S.length();
  if ( isPal(S) && isPal(S.substr(0, L/2)) && isPal(S.substr(1+L/2)) ) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
