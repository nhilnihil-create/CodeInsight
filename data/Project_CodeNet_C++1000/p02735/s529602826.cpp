#include<bits/stdc++.h>
#define ll long long int
#define loop(i,a,b) for(i=a;i<b;i++)
#define mod   998244353
#define INF 1000000000000
#define pb push_back
#define lim 200001
using namespace std;

int main()
{
  ll h,w,i,j;
  cin>>h>>w;
  char s[h+1][w+1];
  ll dp[h+1][w+1];
  loop(i,0,h)
    cin>>s[i];
  dp[0][0]=0;
  
  
  loop(i,0,h)
    loop(j,0,w)
  {if(!i && !j) 
  { if(s[0][0]=='#')
    dp[0][0]=1;
   continue;}
   dp[i][j]=INF;
  if(i>0)
    {dp[i][j]=dp[i-1][j];
     if(s[i-1][j]=='.' && s[i][j]=='#') dp[i][j]++;
    }
    if(j>0)
    {if(s[i][j-1]=='.' && s[i][j]=='#') 
      dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
     else
       dp[i][j]=min(dp[i][j],dp[i][j-1]);}
  }
  
  cout<<dp[h-1][w-1]<<endl;
       return 0;}
  