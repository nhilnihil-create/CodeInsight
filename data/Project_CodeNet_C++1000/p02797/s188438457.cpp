#include<bits/stdc++.h>
using namespace std;

int main(void){
   long long N,K,S;
   cin>>N>>K>>S;
   vector<long long> ans(N);
   if(S<1000000000){
      for(int i=0;i<N;i++){
         if(i<K) ans[i]=S;
         else ans[i]=S+1;
      }
   }else{
      for(int i=0;i<N;i++){
         if(i<K) ans[i]=S;
         else ans[i]=S-1;
      }
   }
   for(int i=0;i<N;i++){
      cout<<ans[i]<<" ";
   }
   cout<<endl;
   return 0;
}
