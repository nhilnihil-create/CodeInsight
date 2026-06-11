#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(void){
   string S;
   cin>>S;
   int N=S.size();
   vector<int> ans(N);
   for(int i=0;i<N;i++){
      if(S[i]=='R'&&S[i+1]=='L'){
         int rcnt=0,lcnt=0;
         int j=i;
         while(j>=0&&S[j]=='R'){
            j--;
            rcnt++;
         }
         j=i+1;
         while(j<N&&S[j]=='L'){
            j++;
            lcnt++;
         }
         ans[i]+=(rcnt+1)/2+lcnt/2;
         ans[i+1]+=(lcnt+1)/2+rcnt/2;
      }
   }
   for(int i=0;i<N;i++){
      if(i==N-1){
         cout<<ans[i]<<endl;
      }else{
         cout<<ans[i]<<" ";
      }
   }
   return 0;
}