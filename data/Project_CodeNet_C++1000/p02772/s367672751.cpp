#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> A(n);

   for(int i=0; i<n; i++) {
      cin >> A[i];
      if(A[i] % 2 == 0) {
         if(A[i] % 3 != 0 && A[i] % 5 != 0) {
            cout << "DENIED" << endl;
            return 0;
         }
      }
   }
   cout << "APPROVED" << endl;
}