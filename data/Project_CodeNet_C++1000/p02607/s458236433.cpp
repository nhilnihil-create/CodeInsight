#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,ans;
  cin>>n;
  ans=0;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
  }
  for(int i=0;i<n;i+=2)
  {
    if(a.at(i)%2!=0)
      ans++;
  }
  cout<<ans<<endl;
}