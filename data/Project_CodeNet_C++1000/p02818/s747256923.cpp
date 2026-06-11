#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int a,b,k;
  cin>>a>>b>>k;
  if(k==0)
  {
      cout<<a<<" "<<b;
  }
  else if(a+b<=k)
  {
      cout<<0<<" "<<0;
  }
  else if(a<=k && a+b>=k)
  {
          cout<<0<<" "<<abs(k-a-b);
  }
  else if(a>=k)
  {
      cout<<abs(a-k)<<" "<<b;
  }

  return 0;


}
