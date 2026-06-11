#include <bits/stdc++.h>
using namespace std;

int main() {
   long N;
   cin >> N;
   vector<long> A;

   for(int i=1; i<=N; i++) {
      if(i % 3 != 0 && i % 5 != 0) {
         A.push_back(i);
      }
   }

   long sum = 0;
   for(int i=0; i<A.size();i++) {
      sum += A[i];
   }
   cout << sum << endl;
}