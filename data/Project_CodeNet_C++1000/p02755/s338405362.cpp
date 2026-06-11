#include "bits/stdc++.h"
using namespace std;

int main()
{
  int a,b,c;
  cin>>a>>b;
  if(a%2==0)
    c=a*12.5;
  else
    c=a*12.5+1;
  for(int i=c;;i++)
  {
    int x,y;
    x=i*0.08;
    y=i*0.1;
    if((x==a)&&(y==b))
    {
      cout<<i<<endl;
      break;
    }
    else if(x!=a)
    {
      cout<<"-1"<<endl;
      break;
    }
  }
}