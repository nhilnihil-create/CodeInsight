#include<bits/stdc++.h>
#define F(i,x,y) for(int i=x;i<y;i++)
#define ll long long;
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int c1=0,t=0;
  char ch;
  while(cin>>ch)
  {
    if(ch=='R')
    {
      c1++;
      if(c1>t)
        t=c1;
    }
    else
    {
      c1=0;
    }
  }
  cout<<t;
}