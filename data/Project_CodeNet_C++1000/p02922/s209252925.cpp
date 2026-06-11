#include <bits/stdc++.h>
using namespace std;

int main(void) {
   int a, b;
   cin >> a >> b;
   a = a - 1;
   b = b - 1;
   if(b % a > 0) {
      cout << b / a + 1;  
   } else {
      cout << b / a;
   }
   return 0;
}

