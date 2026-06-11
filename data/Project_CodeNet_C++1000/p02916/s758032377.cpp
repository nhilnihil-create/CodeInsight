#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
   int n;
   cin>>n;
   int A[n],B[n],C[n-1];
   rep(i,n)cin>>A[i];
   rep(i,n)cin>>B[i];
   rep(i,n-1)cin>>C[i];

   int ans=0;
   rep(i,n)ans+=B[i];

   rep(i,n-1){
       if(A[i+1]-A[i]==1)ans+=C[A[i]-1];
   }

   cout<<ans<<endl;
}