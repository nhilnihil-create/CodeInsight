#include <bits/stdc++.h>
using namespace std;

int main() {
 int a,b,c;
 cin >> a;
 b = -1;
 c = 7;
 for(int i = 1;i<=a;i++){
   if(c%a==0) {
     b = i;
     break;
   }
   c = c%a*10+7;
 }
  cout << b << endl;
}