#include <bits/stdc++.h>
using namespace std;

int main() {
   int N,M;
   cin >> N >> M;
   int total = 0;
   vector<int> A(N);
   for(int i=0; i<N; i++) {
      cin >> A[i];
      total += A[i];
   }

   sort(A.begin(), A.end());
   reverse(A.begin(), A.end());
   double limit = (double)total / (4.0 * M);

   for(int i=0; i<M; i++) {
      if(A[i] < limit) {
         cout << "No" << endl;
         return 0;
      }
   }
   cout << "Yes" << endl;
}