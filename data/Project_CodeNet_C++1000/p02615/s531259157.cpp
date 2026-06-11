#include <bits/stdc++.h>
using namespace std;
 
int main() {
   long long N;
   cin >> N;
   vector<long long> A(N);
   for (int i=0;i<N;i++) {
       cin >> A[i];
   }
   sort(A.begin(),A.end());
   reverse(A.begin(),A.end());
   
   long long ans=A[0];
   if(N!=2) {
   for (int i=1;i<N/2;i++) {
       ans+=2*A[i];
   } 
   if (N%2==1) {
       ans+=A[N/2];
   }
   }
   cout << ans << endl;
}