#include <algorithm>
#include <iostream>
#include <string.h>

int main()
{
    unsigned long long int a;
    std::string s = "";
    std::cin >> a;
  
    while(true){
      char b = 'a' + ((a - 1) % 26);
      s += b;
      a = (a - 1) / 26;
      if (a <= 0) break;
    }
  
    std::reverse(s.begin(), s.end());
    std::cout << s << std::endl;
}