#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int a; std::string s; std::cin >> a >> s;
  if(a < 3200) s = "red";
  fin(s);
  return 0;
}