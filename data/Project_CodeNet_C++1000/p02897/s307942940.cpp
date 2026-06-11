#include <bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin >> n;
   double a, b;
   int i;
   for(i = 1; i <= n; i++){
       b += 1.0;
       if(i % 2 == 1){
           a += 1.0;
       }
   }
   cout << a/b << endl;
   return 0;
}
