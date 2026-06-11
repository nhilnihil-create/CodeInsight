#include <iostream>
#include <string>

int main()
{
  std::string S;
  std::cin >> S;
  if(S[2] == S[3] && S[4] == S[5]) std::cout << "Yes";
  else std::cout << "No";
}
