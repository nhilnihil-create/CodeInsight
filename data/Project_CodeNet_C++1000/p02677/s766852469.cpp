#include<bits/stdc++.h>
using namespace std;

int z(int x)
{
  if(x<0)
    return x*-1;
  else
    return x;
}

int main()
{
  int a,b,h,m;
  double rad,ans;
  cin>>a>>b>>h>>m;
  rad=z(h*60-m*11)*M_PI/360;
  cout<<fixed<<setprecision(15);
  cout<<sqrt(a*a+b*b-2*b*a*cos(rad))<<endl;
}