#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<char> S(N);
   for(int i=0;i<N;i++){
      cin>>S[i];
   }
   long long cnt_R=0,cnt_G=0,cnt_B=0;
   for(int i=0;i<N;i++){
      if(S[i]=='R') cnt_R++;
      if(S[i]=='G') cnt_G++;
      if(S[i]=='B') cnt_B++;
   }
   long long ans=cnt_R*cnt_G*cnt_B;
   for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
         int k=2*j-i;
         if(k<N){
            if(S[i]!=S[j]&&S[j]!=S[k]&&S[k]!=S[i]){
               ans=ans-1;
            }
         }
      }
   }
   cout<<ans<<endl;
   return 0;
}