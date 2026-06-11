#include<bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n,ans;
  cin>>n;
  ans=1;
  vector<int64_t> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
    if(a.at(i)==0)
    {
      ans=0;
      break;
    }
  }
  for(int i=0;i<n;i++)
  {
    if(ans==0)
    {
      break;
    }
    else if(1000000000000000000/ans<a.at(i))
    {
      ans=-1;
      break;
    }
    ans*=a.at(i);
  }
  cout<<ans<<endl;
}