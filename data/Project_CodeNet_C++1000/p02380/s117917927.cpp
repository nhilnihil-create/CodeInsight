#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  double a,b,c;
  cin>>a>>b>>c;
  c=c*M_PI/180;
  //cout<<c<<endl;
  cout<<fixed<<setprecision(20)<<0.5*a*b*sin(c)<<endl;
  cout<<a+b+sqrt(a*a+b*b-2*a*b*cos(c))<<endl;
  cout<<b*sin(c)<<endl;
}

