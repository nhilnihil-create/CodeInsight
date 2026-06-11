#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace ans
{
  long double val=0.0;
}

int main()
{
  int n;
  cin>>n;
  if(n%2==0)
  {
    ans::val=0.5;
  }
  else
  {
    ans::val=(long double)(n/2+1)/n;
  }
  cout<<ans::val<<endl;
  
  return 0;
}
