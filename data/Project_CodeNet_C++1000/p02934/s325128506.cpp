#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
   int a;
   cin>>a;
   double b;
   double k;
   for(int i = 0;i<a;i++){
     double dd;
     cin >> dd;
     b+=1/dd;
   }
   cout<<1/b;
    return 0;
}