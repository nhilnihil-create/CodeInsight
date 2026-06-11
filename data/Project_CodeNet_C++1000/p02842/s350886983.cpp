#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,x,h;
  h=0;
  cin>>n;
  x=n*25/27;
  for(int i=x-1;i<=x+1;i++)
  {
    if(i*27/25==n)
    {
      h=1;
      cout<<i<<endl;
      break;
    }
  }
  if(h==0)
    cout<<":("<<endl;
}