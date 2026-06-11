#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<long long> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   long long ans=1000;
   long long stock;
   for(int i=0;i<N-1;i++){
      if(A[i]<A[i+1]){
         stock=ans/A[i];
         ans+=(A[i+1]-A[i])*stock;
      }
   }
   cout<<ans<<endl;
   return 0;
}
