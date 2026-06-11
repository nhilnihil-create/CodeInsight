#include <bits/stdc++.h>
using namespace std;

 int main () {
   int a,b;
   cin >> a >> b;
   
   int c=b-a;
   int d=c/2;
   
   if (c%2!=0) {
     cout << "IMPOSSIBLE" << endl;
   }
   else {
     cout << a+d << endl;
   }
 }
