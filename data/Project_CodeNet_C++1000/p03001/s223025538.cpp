#include<bits/stdc++.h>
using namespace std;

int main()
{
  int p;
  double a,b,x,y;
  double ans;
  cin>>a>>b>>x>>y;
  ans=a*b/2;
  if((a/2==x)&&(b/2==y))
    p=1;
  else
    p=0;
  cout<<fixed<<setprecision(10);
  cout<<ans<<' '<<p<<endl;
}