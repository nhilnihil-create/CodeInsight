#include<iostream>
using namespace std;

int main()
{
  int a,b,c,n;
  cin>>a>>b>>c>>n;
  int x=0,y=0;
  while(b<=a)b*=2,x++;
  while(c<=b)c*=2,y++;

  
  if(x+y<=n)cout<<"Yes\n";
  else cout<<"No\n";
}