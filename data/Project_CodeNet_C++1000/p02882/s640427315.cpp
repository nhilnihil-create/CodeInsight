#include <bits/stdc++.h>
using namespace std;

int main(){
  double a,b,x,r;
  cin>>a>>b>>x;
  r=(x<=a*a*b/2.0)? atan((a*b*b)/(2.0*x)): atan((2*(a*a*b-x))/(a*a*a));
  cout<<fixed<<setprecision(10)<<r*180.0/M_PI<<endl;
}