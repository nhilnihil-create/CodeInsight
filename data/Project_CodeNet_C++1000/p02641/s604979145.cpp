#include<iostream>
using namespace std;
int main (void)
{
  int x,n,a[201],p,ans=0,d,i;
  for(i=0;i<=200;i++){a[i]=0;}
  cin>>x>>n;
  for(i=0;i<n;i++)
  {
    cin>>p;
    a[p]=1;
  }
  bool f=0;
  for(i=x;i>=0;i--)
  {
    if(a[i]==0)
    {
      ans=i;
      d=x-i;
      break;
    }
  }
  for(i=x;i<x+d;i++)
  {
    if(a[i]==0)
    {
      ans=i;
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}