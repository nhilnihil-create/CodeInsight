#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

int main()
{
  string S;cin>>S;
  ll n= S.size();
  vector<vector<ll>> DP(n+1,vector<ll>(15,0));
  //DP[i][j]=先頭i文字でj余る数の個数
  
  if (S[0]=='?')
  {
    for (int j=0;j<10;j++)
      DP[0][j]=1;
  }
  else
  {
    int first = S[0]-'0';
    for (int j=0;j<10;j++)
    {
      if (j==first) DP[0][j]=1;
      else DP[0][j]=0;
    }
  }
  
  for (int i=1;i<n;i++)
  {
    if (S[i]=='?')
    {
      for (int j=0;j<13;j++)
      {
        for (int d=0;d<10;d++)
        {
          DP[i][(j*10+d)%13] += DP[i-1][j];
          DP[i][(j*10+d)%13] %= MOD;
        }
      }
    }
    else
    {
      for (int j=0;j<13;j++)
      {
        int d = S[i]-'0';
        DP[i][(j*10+d)%13] += DP[i-1][j]; 
        DP[i][(j*10+d)%13] %= MOD;
      }
    }
  }
  
  /*
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<13;j++)
      cout<<"DP["<<i<<"]["<<j<<"]="<<DP[i][j]<<endl;
  }*/
  
  cout<<DP[n-1][5]<<endl;
} 