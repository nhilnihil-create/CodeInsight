#include<bits/stdc++.h>
using namespace std;

int  main()
{
  int n,k,sum,ans;
  sum=0;
  cin>>n>>k;
  ans=n;
  vector<int> d(k);
  vector<int> a;
  for(int i=0;i<k;i++)
  {
    cin>>d.at(i);
    sum+=d.at(i);
    vector<int> b(d.at(i));
    for(int j=0;j<d.at(i);j++)
    {
      cin>>b.at(j);
      a.push_back(b.at(j));
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<sum;j++)
    {
      if(a.at(j)==i)
      {
        ans--;
        break;
      }
    }
  }
  cout<<ans<<endl;
}