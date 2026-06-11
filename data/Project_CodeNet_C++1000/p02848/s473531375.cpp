#include <iostream>
#include <string>


int main() {
   int n; std::cin >> n;
   std::string s; std::cin >> s;
  
   for (int i = 0; i < (int)s.size(); ++i) {
      char c = s[i] - 65; // 0~25に変換
      c += n;
      c %= 26;
      c += 65;
      std::cout << c;
   }
   std::cout << std::endl;

   return 0;
}
