#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,max,p,q;
  max=0;
  cin>>n;
  vector<int> a(n);
  vector<int> aa(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
    if(max<a.at(i))
    {
      max=a.at(i);
      p=i;
    }
  }
  for(int i=0;i<n;i++)
  {
    aa.at(i)=a.at(i);
  }
  sort(aa.begin(),aa.end());
  reverse(aa.begin(),aa.end());
  for(int i=0;i<n-1;i++)
  {
    if(aa.at(i)!=aa.at(i+1))
    {
      q=aa.at(i+1);
      break;
    }
  }
  if(aa.at(0)==aa.at(1))
  {
    for(int i=0;i<n;i++)
    {
      cout<<max<<endl;
    }
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      if(i!=p)
        cout<<max<<endl;
      else
        cout<<q<<endl;
    }
  }
}