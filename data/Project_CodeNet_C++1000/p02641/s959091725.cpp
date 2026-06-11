#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n,x,i;
  cin>>x>>n;
  if(n==0)
  {
     cout<<x<<'\n';
     return 0;
  }
  int a;
  vector<int>v;
  for(i=0;i<n;i++)
   {
       cin>>a;
       v.push_back(a);
   }
   int k=0,p=0,q=0;
  while(1)
  {
    p=x-k;
    q=x+k;

    auto it1=find(v.begin(),v.end(),p);
    if(it1==v.end())
    {
        cout<<p<<'\n';
        return 0;
    }
    auto it2=find(v.begin(),v.end(),q);
    if(it2==v.end())
    {
        cout<<q<<'\n';
        return 0;
    }
    k++;
  }
}
