#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,d,ans;
  ans=0;
  cin>>n>>d;
  vector<vector<int>> x(n,vector<int>(d));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<d;j++)
    {
      cin>>x.at(i).at(j);
    }
  }
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int disdis=0;
      int han;
      double dis;
      for(int k=0;k<d;k++)
      {
        disdis+=(x.at(i).at(k)-x.at(j).at(k))*(x.at(i).at(k)-x.at(j).at(k));
      }
      dis=sqrt(disdis);
      han=dis;
      if(dis==han)
        ans++;
    }
  }
  cout<<ans<<endl;
}