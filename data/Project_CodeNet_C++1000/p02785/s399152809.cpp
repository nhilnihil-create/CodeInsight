#include<bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n,k,ans;
  ans=0;
  cin>>n>>k;
  vector<int64_t> hp(n);
  for(int i=0;i<n;i++)
  {
    cin>>hp.at(i);
  }
  sort(hp.begin(), hp.end());
  if(n<=k)
    cout<<ans<<endl;
  else
  {
    for(int i=0;i<k;i++)
    {
      hp.pop_back();
    }
    for(int i=0;i<n-k;i++)
    {
      ans+=hp.at(i);
    }
    cout<<ans<<endl;
  }
}