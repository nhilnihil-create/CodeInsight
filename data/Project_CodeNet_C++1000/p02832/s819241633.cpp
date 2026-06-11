#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,k,ans;
  k=1;
  cin>>n;
  ans=n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
  }
  for(int i=0;i<n;i++)
  {
    if(a.at(i)==k)
    {
      ans--;
      k++;
    }
  }
  if(k!=1)
    cout<<ans<<endl;
  else
    cout<<"-1"<<endl;
}