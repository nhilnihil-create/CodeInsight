#include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  if(a>=b&&a>=c) cout<<b+c;
  else if(b>=c&&b>=a) cout<<a+c;
  else if(c>=b&&c>=a) cout<<b+a;
}