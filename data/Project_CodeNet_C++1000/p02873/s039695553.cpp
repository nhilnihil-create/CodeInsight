#include<bits/stdc++.h>
using namespace std;

int main(void){
   string S;
   cin>>S;
   int N=S.size();
   vector<int> A(N+1,0);
   for(int i=0;i<N;i++){
      if(S[i]=='<'){
         A[i+1]=max(A[i+1],A[i]+1);
      }
   }
   for(int i=N-1;i>=0;i--){
      if(S[i]=='>'){
         A[i]=max(A[i+1]+1,A[i]);
      }
   }
   long long ans=0;
   for(int i=0;i<N+1;i++){
      ans+=A[i];
   }
   cout<<ans<<endl;
   return 0;
}
