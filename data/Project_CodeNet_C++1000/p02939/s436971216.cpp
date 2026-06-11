#include <iostream>
#include <string>

int main(){
   std::string S;
   std::cin >> S;
   std::string subS = "";
   int i = 0;
   int k = 0;
   while (i < S.size()){
      k++;
      if (subS == S.substr(i, 1)){
         subS = S.substr(i, 2);
         i += 2;
         if (i > S.size()){
            k--;
         }
      } else{
         subS = S.substr(i, 1);
         i++;
      }
   }
   std::cout << k << std::endl;

}

