#include "bits/stdc++.h"
using namespace std;

int main()
{
  int a,b,c,count,k;
  count=0;
  cin>>a>>b>>c>>k;
  while(a>=b)
  {
    b*=2;
    count++;
  }
  while(b>=c)
  {
    c*=2;
    count++;
  }
  if(k>=count)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}