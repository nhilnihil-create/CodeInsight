#include <iostream>
#include <string>

int main()
{
  std::string S;
  std::cin >> S;
  int l = S.length();
  int cnt = 0;
  for (int i=0; i<l/2; i++) {
    if (S[i] != S[l-1-i]) cnt++;
  }
  std::cout << cnt << std::endl;
  return 0;
}
