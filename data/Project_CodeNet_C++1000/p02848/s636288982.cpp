#include <iostream>
#include <string>


int main() {
   int n; std::cin >> n;
   std::string s; std::cin >> s;
  
   for (int i = 0; i < (int)s.size(); ++i) {
      char c = s[i] - 'A'; // 0~25に変換
      c = (c+n) % 26;
      c += 'A';
      std::cout << c;
   }
   std::cout << std::endl;

   return 0;
}
