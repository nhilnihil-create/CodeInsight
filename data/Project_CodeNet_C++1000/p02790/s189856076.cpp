#include <bits/stdc++.h>
using namespace std;

int main() {
   string a, b;
   cin >> a >> b;
   string x = "", y="";

   for(int i=0; i<stoi(b); i++) {
      x += a;
   }
   for(int i=0; i<stoi(a); i++) {
      y += b;
   }


   if(x >= y) cout << y;
   else cout << x;
}