#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


int main() {
   long long a,b,c;
 
   cin >> a >> b >> c;
   long long ans = 0;
  
   
   if (a < c){
     
     c = c - a;
     a = 0;
     if (b < c){
       b = 0;
       cout << a << " "<< b << endl;
     }else {
       b = b - c;
       cout << a << " "<< b << endl;
     }
     
   }else {
     a = a - c;
      cout << a << " "<< b << endl;
   }
   
   
  
  
   
  return 0;
}