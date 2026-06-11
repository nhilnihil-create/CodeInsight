#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,ans;
  cin>>a>>b;
  ans = 0;
  ans+=a*(a-1)/2;
  ans+=b*(b-1)/2;
  cout<<ans<<endl;
  return 0;
}
