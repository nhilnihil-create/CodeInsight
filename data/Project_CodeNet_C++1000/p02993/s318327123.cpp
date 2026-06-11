#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::string S; std::cin >> S;
  for(int i = 0; i < 3; ++i) if(S[i] == S[i+1]) fin("Bad");
  fin("Good");
  return 0;
}
