#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, M;
   cin >> N >> M;
   vector<int> A(M);
   int total_day = 0;
   for(int i=0; i<M; i++) {
      cin >> A[i];
      total_day += A[i];
   }

   if(N < total_day) {
      cout << -1 << endl;
      return 0;
   }

   cout << N - total_day << endl;
}