#include <bits/stdc++.h>
using namespace std;

int main() {
   int A, B, C, K;
   cin >> A >> B >> C >>K;

   if(K <= A) {
      cout << 1 * K << endl;
      return 0;
   }
   else if(K > A && K <= B) {
      cout << A * 1 << endl;
      return 0;
   }
   else {
      cout << A * 1 - (K - A - B) << endl;
      return 0;
   }
}