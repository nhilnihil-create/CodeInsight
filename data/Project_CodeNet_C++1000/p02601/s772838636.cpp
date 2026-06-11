#include<iostream>
using namespace std;
int main()
{
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  while(k>0)
  {
    if(b<=a)
    	b*=2;
   	else if(c<=b)
      c*=2;
    else
    {}
    k--;
  }
  if(c>b&&b>a)
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}