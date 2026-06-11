#include <iostream>
#include <string>

using namespace std;

int main(void){

   int x;
   cin >> x;

   if(x <100){
      cout << 0 << endl;
      return 0;
   }

   if(x %100 == 0){
      cout << 1 << endl;
      return 0;
   }
   int xx = x / 100;
   int mod = x % 100;

   puts(5*xx >= mod ? "1" : "0");
   return 0;
}