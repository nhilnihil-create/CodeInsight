#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main() 
{
int n,m,x;
cin>>n>>m>>x;
int arr[n][m+1];

for(int i=0;i<n;i++)
{
          for(int j=0;j<=m;j++)
          {
                    cin>>arr[i][j];
          }
}
int cost=INT_MAX;
for(int it=0;it<(1<<n);it++)
{     vector<int>dp(m+1,0);
      int temp=0;
          for(int i=0;i<n;i++)
          {
                    if((it&(1<<i))==0) continue;
                     
                     for(int j=1;j<=m;j++)
                     {
                         dp[j]+=arr[i][j];      
                     }
                     temp+=arr[i][0];
                     
          }
          bool ch=1;
          for(int j=1;j<=m;j++)
          {
                    if(dp[j]<x) ch=0;
          }
          if(ch==1)
          {
                    cost=min(cost,temp);
          }
}
if(cost==INT_MAX)
{
          cout<<-1<<"\n";
}
else
{
          cout<<cost<<"\n";
}
}
