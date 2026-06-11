#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,m,ans;
  ans=0;
  cin>>n>>m;
  vector<pair<int,int>> a(m);
  if(m==0)
  {
    if(n==1)
      ans=0;
    if(n==2)
      ans=10;
    if(n==3)
      ans=100;
  }
  else
  {
    for(int i=0;i<m;i++)
    {
      cin>>a.at(i).first>>a.at(i).second;
    }
    sort(a.begin(),a.end());

    if(n!=1)
    {
      if((a.at(0).first==1)&&(a.at(0).second==0))
        ans=-1;
    }
    if(m!=1)
    {
      for(int i=0;i<m-1;i++)
      {
        if(a.at(i).first==a.at(i+1).first)
        {
          if(a.at(i).second!=a.at(i+1).second)
          {
            ans=-1;
            break;
          }
        }
      }
    }
    if(m!=1)
    {
      for(int i=0;i<m-1;i++)
      {
        if((a.at(i).first==a.at(i+1).first)&&(a.at(i).second==a.at(i+1).second))
          a.at(i).first=100;
      }
    }

    if(ans!=-1)
    {
      if(n==1)
        ans=a.at(0).second;
      else if(n==2)
      {
        for(int i=0;i<m;i++)
        {
          if(a.at(i).first==1)
            ans+=a.at(i).second*10;
          if(a.at(i).first==2)
            ans+=a.at(i).second;
        }
        if(ans<10)
        {
          ans+=10;
        }
      }
      else
      {
        for(int i=0;i<m;i++)
        {
          if(a.at(i).first==1)
            ans+=a.at(i).second*100;
          if(a.at(i).first==2)
            ans+=a.at(i).second*10;
          if(a.at(i).first==3)
            ans+=a.at(i).second;
        }
        if(ans<100)
        {
          ans+=100;
        }
      }
    }
  }
  cout<<ans<<endl;
}