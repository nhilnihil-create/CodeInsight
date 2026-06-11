#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, D;
   cin >> N >> D;
   int v[D][N];
   int count=0;

   for(int i=0; i<N; i++) {
      for(int j=0; j<D; j++) {
         cin >> v[j][i];
      }
   }

   for(int i=0; i<N-1; i++) {
      for(int j=i+1; j<N; j++) {
         int sum = 0;
         for(int k=0; k<D; k++) {
            sum += pow((abs(v[k][i]-v[k][j])), 2);
         }
         int r = (int)(sqrt(sum));
         if(r * r == sum) {
            count++;
         }
      }
   }
   cout << count << endl;
}