#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  if(m==0)
  {
    cout<<0<<" "<<0<<endl;
  }
  else
  {
    int a,b;
    a=0;
    b=0;
    vector<int> q(n);
    vector<int> mis(n);
    vector<pair<int,string>> s(m);
    for(int i=0;i<m;i++)
    {
      cin>>s.at(i).first>>s.at(i).second;
    }
    for(int i=0;i<m;i++)
    {
      if(q.at(s.at(i).first-1)==0)
      {
        if(s.at(i).second=="WA")
        {
          b++;
          mis.at(s.at(i).first-1)++;
        }
        else
        {
          a++;
          q.at(s.at(i).first-1)=1;
        }
      }
    }
    for(int i=0;i<n;i++)
    {
      if(q.at(i)==0)
        b-=mis.at(i);
    }
    cout<<a<<" "<<b<<endl;
  }
}