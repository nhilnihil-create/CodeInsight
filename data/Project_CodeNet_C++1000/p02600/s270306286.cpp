#include<iostream>
using namespace std;
int main()
{
  int x,s=400,t=599,m=8,r=0;
  cin>>x;
  for(int i=0;i<9;i++)
  {
    if(x>=s && x<=t)
    {
      r=m;
      break;
    }
    else
    {
      s=t+1;t=t+200;
      m--;
    }
  }
  cout<<r;
  return 0;
}