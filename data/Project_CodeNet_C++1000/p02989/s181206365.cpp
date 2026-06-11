#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,ans;
  ans=0;
  cin>>n;
  vector<int> d(n);
  for(int i=0;i<n;i++)
  {
    cin>>d.at(i);
  }
  sort(d.begin(),d.end());
  if(d.at(n/2-1)!=d.at(n/2))
  {
    for(int i=d.at(n/2);i>d.at(n/2-1);i--)
    {
      ans++;
    }
  }
  cout<<ans<<endl;
}