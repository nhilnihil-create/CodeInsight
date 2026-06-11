#include<iostream>
using namespace std;
int main (void)
{
  long long int a,b,c,n,ans;
  int i;
  cin>>n>>a>>b;
  c=0;
  i=0;
  ans=n/(a+b);
  ans=ans*a;
  //cout<<ans;
  
  if((n%(a+b))>a)ans+=a;
  else ans=ans+(n%(a+b));
  cout<<ans;
  
}