#include <iostream>

using namespace std;

int main(){
   int l, r, d;
   cin >> l >> r >> d;
   int res = 0;
   for(l = l; l <= r; l++){
     if((l % d) == 0){
        res++;
     }
   }
  cout << res << "\n";
   return 0; 
}