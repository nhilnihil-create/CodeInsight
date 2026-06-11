#include "bits/stdc++.h"
using namespace std;

int main()
{
  double a,b,x;
  double v;
  cin>>a>>b>>x;
  v=a*a*b/2;
  if(x<=v)
  {
    double h,r;
    h=x*2/b/a;
    r=90-atan(h/b)*180/M_PI;
    cout<<fixed<<setprecision(10);
    cout<<r<<endl;
  }
  else
  {
    double h,r;
    h=(a*a*b-x)*2/a/a;
    r=atan(h/a)*180/M_PI;
    cout<<fixed<<setprecision(10);
    cout<<r<<endl;
  }
}