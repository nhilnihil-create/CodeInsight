#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  while(!(b>a))
  {
    b*=2;
    k--;
  }
  while(!(c>b))
  {
    c*=2;
    k--;
  }
  
  if(k>=0)
  {
    cout<<"Yes";
  }
  else
  {
    cout<<"No";
  }
  return 0;
}