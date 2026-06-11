#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,ans;
  ans=0;
  cin>>n;
  vector<int> a(n,100001);
  vector<int> b(n-1);
  for(int i=0;i<n-1;i++)
  {
    cin>>b.at(i);
  }
  for(int i=0;i<n-1;i++)
  {
    a.at(i)=min(b.at(i),a.at(i));
    a.at(i+1)=min(b.at(i),a.at(i+1));
  }
  for(int i=0;i<n;i++)
  {
    ans+=a.at(i);
  }
  cout<<ans<<endl;
}