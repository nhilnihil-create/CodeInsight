#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  long long ans=0,tmp;
  cin>>n;
  for(int i=1;i<=n;++i)
  {
    tmp=n/i;
    ans+=(i+tmp*i)*tmp/2;
  }
  cout<<ans;
  return 0;
}