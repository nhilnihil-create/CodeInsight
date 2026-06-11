#include<bits/stdc++.h>
using namespace std;

  
int main()
{
  long long n;
  cin>>n;
  int res=1;
  for(int i=sqrt(n);i>=2;i--)
  {
    if(n%i==0)
    {
      res=i;
      break;
    }
  }
  cout<<res+n/res-2;
}
