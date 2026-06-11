#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<long long> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   vector<long long> sum(N+1,0);
   sum[0]=0;
   for(int i=0;i<N;i++){
      sum[i+1]=sum[i]+A[i];
   }
   long long ans=2500000000;
   for(int i=1;i<=N;i++){
      long long temp=0;
      temp=abs(sum[N]-2*sum[i]);
      ans=min(temp,ans);
   }
   cout<<ans<<endl;
   return 0;
}
