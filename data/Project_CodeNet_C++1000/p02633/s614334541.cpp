#include<bits/stdc++.h>
using namespace std;

int main()
{
  int x;cin>>x;
  for(int k=1;k<=360;++k)
  {
    if((k*x)%360==0)
    {
      cout<<k<<endl;
      break;
    }
  }
  return 0;
}
  