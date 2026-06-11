#include <bits/stdc++.h>
using namespace std;

int main() {
   int A, B, C, D;
   cin >> A >> B >> C >> D;

   for(;;) {
      C -= B;
      A -= D;
      if(C <= 0) {
         cout << "Yes" << endl;
         return 0;
      }
      else if(A <= 0) {
         cout << "No" << endl;
         return 0;
      }
   }
}