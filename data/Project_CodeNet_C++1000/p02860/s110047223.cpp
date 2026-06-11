#include <iostream>
#include <string>

int main()
{
  int N;
  std::string S;
  std::cin >> N;
  std::cin >> S;
  if (N%2==0) {
    bool flg = true;
    for (int i=0; i<N/2; i++) {
      if (S[i] != S[N/2+i]) {
        flg = false; break;
      }
    }
    if (flg) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
  }
  else std::cout << "No" << std::endl;
  return 0;
}