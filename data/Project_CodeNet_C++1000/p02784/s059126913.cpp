#include <bits/stdc++.h>
using namespace std;

int main() {
   int H, N,sum=0;
   cin >> H >> N;
   vector<int> A(N);

   for(int i=0; i<N; i++) {
      cin >> A[i];
      sum += A[i];
   }
   if(sum >= H) cout << "Yes" << endl;
   else cout << "No" << endl;
}