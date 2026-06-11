#include<bits/stdc++.h>
using namespace std;

int main()
{
  int64_t a,b,k,ans;
  cin>>a>>b>>k;
  if(a>k)
  {
    cout<<a-k<<" "<<b<<endl;
  }
  else
  {
    ans=a+b-k;
    if(ans<0)
      ans=0;
    cout<<"0"<<" "<<ans<<endl;
  }
}