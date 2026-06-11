#include<bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n,ans;
  cin>>n;
  ans=0;
  if(n%2==0)
  {
    for(int64_t i=10;;i*=5)
    {
      int64_t v=n/i;
      ans+=v;
      if(v==0)
        break;
    }
  }
  cout<<ans<<endl;
}