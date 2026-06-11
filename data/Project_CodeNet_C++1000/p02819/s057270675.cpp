#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
 const int n = 1e6+ 5;
 bool Is_Brime(int x) {
     if (x <= 1)
         return false;
     for (int i = 2; i * i <= x; i++) {
         if (x % i == 0) {
             return false;
         }
     }
     return true;
 }
     int main(){
         int x;
         cin >> x;
         while (true) {
             if (Is_Brime(x)) {
                 cout << x << endl;
                 return 0;

             }
             x++;
         }
   
    
     }