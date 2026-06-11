#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n;
  cin>>n;
  for(int i=n;;i++)
  {
    int h=1;
    for(int j=2;j<=sqrt(i);j++)
    {
      if(i%j==0)
      {
        h=0;
        break;
      }
    }
    if(h==1)
    {
      cout<<i<<endl;
      break;
    }
  }
}