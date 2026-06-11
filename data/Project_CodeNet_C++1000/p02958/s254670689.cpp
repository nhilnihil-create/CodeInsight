#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, min_j;
   cin >> N;
   vector<int> A(N);
   int count = 0;

   for(int i=0; i<N; i++) cin >>A[i];
   
   for(int i=0; i<N-1; i++) {
      min_j=i;
      for(int j=i; j<N; j++) {
         if(A[j] < A[min_j]) min_j = j;
      }
      swap(A[i], A[min_j]);
      if(i != min_j) count++;
   }

   if (count <= 1) {
      cout << "YES" << endl;
   }
   else cout<< "NO" << endl;
}