#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int i,x,t,p;
  cin>>x;
  i=0;
  t=100;
  while(t<x)
  {
      p=(t*1)/100;
      t=t+p;
      i++;
  }
  cout<<i;
}
