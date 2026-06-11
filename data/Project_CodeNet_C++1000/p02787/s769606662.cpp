#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
const ll N = 1e5+10 ;
int w[N],v[N];
int dp[N];
int main(){
   int n,k;
   cin >> n >> k;
   int m = -1;
   memset(dp,0x3f,sizeof dp);
   dp[0] = 0;
   for(int i = 1;i <= k;++i) {cin>>w[i]>>v[i];}
   for(int i = 1;i <= k;++i){
      for(int j = w[i];j <= 1e4;++j){
         if(dp[j-w[i]] != 0x3f3f3f3f) dp[j] = min(dp[j],dp[j-w[i]] + v[i]);
      }
   }
   m = 0x3f3f3f3f;
   for(int i = n;i <= 1e4;++ i){
      m = min(m,dp[i]);
   }
   cout<<m<<endl;
}
