#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define INF 1000000

int main()
{
  int h,w;cin>>h>>w;
  vector<vector<char>> s(h,vector<char>(w));
  int i,j;
  rep(i,h)rep(j,w)cin>>s[i][j];
  vector<vector<int>> dp_modoki(h,vector<int>(w,INF));
  dp_modoki[0][0]=0;
  if(s[0][0]=='#')dp_modoki[0][0]=1;
  rep(i,h)
  {
    rep(j,w)
    {
      if(i==0&&j==0)continue;
      if(i==0)
      {
        if(s[i][j-1]=='.'&&s[i][j]=='#')
        {
          dp_modoki[i][j]=dp_modoki[i][j-1]+1;
        }
        else dp_modoki[i][j]=dp_modoki[i][j-1];
      }
      else if(j==0)
      {
        if(s[i-1][j]=='.'&&s[i][j]=='#')
        {
          dp_modoki[i][j]=dp_modoki[i-1][j]+1;
        }
        else dp_modoki[i][j]=dp_modoki[i-1][j];
      }
      else
      {
        int down=dp_modoki[i-1][j];
        int right=dp_modoki[i][j-1];
        if(s[i-1][j]=='.'&&s[i][j]=='#')down++;
        if(s[i][j-1]=='.'&&s[i][j]=='#')right++;
        dp_modoki[i][j]=min(down,right);
      }
    }
  }
  cout<<dp_modoki[h-1][w-1]<<endl;
} 
