#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int h,w;
  cin>>h>>w;
  vector<vector<char> >a(h);
  vector<vector<int> >r(h);
  vector<vector<int> >re(h);
  for(int i=0;i<h;i++)
  {
  	a[i].resize(w);
    r[i].resize(w);
    int t=-1;
    for(int j=0;j<w;j++)
    {
      cin>>a[i][j];
      if(a[i][j]=='#')
      {
        t=j;
      }
      r[i][j]=t;
    }
  }
  for(int i=0;i<h;i++)
  {
    re[i].resize(w);
    int t=w;
    for(int j=w-1;j>=0;j--)
    {
      if(a[i][j]=='#')
      {
        t=j;
      }
      re[i][j]=t;
    }
  }
  
  
  vector<vector<int> >c(h);
  for(int j=0;j<w;j++)
  {
    int t=-1;
    for(int i=0;i<h;i++)
    {
      if(j==0)c[i].resize(w);
      if(a[i][j]=='#')
      {
        t=i;
      }
      c[i][j]=t;
    }
  }
  vector<vector<int> >ce(h);
  for(int j=0;j<w;j++)
  {
    int t=h;
    for(int i=h-1;i>=0;i--)
    {
      if(j==0)ce[i].resize(w);
      if(a[i][j]=='#')
      {
        t=i;
      }
      ce[i][j]=t;
    }
  }
  int ans=0;
  for(int i=0;i<h;i++)
  {
    
    for(int j=0;j<w;j++)
    {
      int t=0;
      if(a[i][j]=='#')continue;
      t+=(j-r[i][j]-1);
      t+=(re[i][j]-j-1);
      t+=(i-c[i][j]-1);
      t+=(ce[i][j]-i-1);
      t++;
      if(t>ans)ans=t;
      //cout<<t<<" ";
    }
    //cout<<endl;
  }
  cout<<ans<<endl;
 //cout<<c[0][1]<<endl;
  return 0;
}