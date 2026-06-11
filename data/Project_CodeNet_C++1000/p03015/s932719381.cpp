#include "bits/stdc++.h"
using namespace std;
using ll=long long;

const int MOD=1e9+7;

const int MAX_N=1e5;

ll dp[MAX_N][2];
string L;

ll rec(int k=0,bool tight=true){
   if(k==L.length()) return 1;
   
   if(dp[k][tight]!=-1) return dp[k][tight];
   else dp[k][tight]=0;

   if(tight){
      if(L[k]=='1'){
         dp[k][tight]+=2*rec(k+1,true);
         dp[k][tight]+=rec(k+1,false);
      }else{
         dp[k][tight]+=rec(k+1,true);
      }
   }else{
      dp[k][tight]+=3*rec(k+1,false);
   }

   return dp[k][tight]%=MOD;
}

int main(){
   cin>>L;
   for(int i=0;i<L.length();++i) for(int j=0;j<2;++j) dp[i][j]=-1;
   
   ll ans=rec();
   ans%=MOD;
   cout<<ans<<endl;
}