#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,x,y;
  cin>>n>>x>>y;
  int INF=n;
  vector<vector<int> >dis(n);
  vector<int>ans(n);
  for(int i=0;i<n;i++)
  {
    dis[i].resize(n,INF);
   	if(i!=0)dis[i][i-1]=1;
    dis[i][i]=0;
   	if(i!=n-1)dis[i][i+1]=1;
  }
  dis[x-1][y-1]=1;
  dis[y-1][x-1]=1;
  for(int i=0;i<n;i++)
  {
    if(i==y-1)continue;
    dis[x-1][i]=min(abs(x-1-i),dis[x-1][y-1]+abs(y-1-i));
    dis[y-1][i]=min(abs(y-1-i),dis[y-1][x-1]+abs(x-1-i));
  }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        dis[i][j]=min(abs(i-j),dis[i][x-1]+dis[x-1][j]);
        if(j>i)ans[dis[i][j]]++;
        //cout<<dis[i][j]<<' ';
      }
      //cout<<endl;
    }
  for(int i=1;i<n;i++)cout<<ans[i]<<endl;
  return 0;
}