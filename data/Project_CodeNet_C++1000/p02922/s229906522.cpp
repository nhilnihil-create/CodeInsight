#include <bits/stdc++.h>
using namespace std;

int main() {
   int A, B;
   cin >> A >>B;
   int plague_count = A;
   int count = 1;

   if(B <= 1) {
      cout << 0 << endl;
      return 0;
   }

   for(;;) {
      if(plague_count >= B) {
         cout << count << endl;
         return 0;
      }
      plague_count += A-1;
      count++;
   }

}