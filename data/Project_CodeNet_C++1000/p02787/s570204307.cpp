#include<bits/stdc++.h>
using namespace std;int h,n,a,b,i,j,k;main(){cin>>h>>n;vector<int>dp(h+1,1e9);dp[0]=0;for(i=0;i<n;i++){cin>>a>>b;for(j=0;j<h;j++)k=min(j+a,h),dp[k]=min(dp[k],dp[j]+b);}cout<<dp[h]<<"\n";}
