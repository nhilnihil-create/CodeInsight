#include<iostream>
using namespace std;
int main()
{
  int a,b,ans=0;
  cin>>a>>b;
  if(a==1) ans+=300000;
  if(b==1) ans+=300000;
  if(a==2) ans+=200000;
  if(b==2) ans+=200000;
  if(a==3) ans+=100000;
  if(b==3) ans+=100000;
  if(a==1&&b==1) ans+=400000;
  cout<<ans;
}