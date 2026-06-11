#include<bits/stdc++.h>
using namespace std;
int main(){
  cout<<fixed<<setprecision(12);
  double a,b,c;
  cin>>a>>b>>c;
  double PI=acos(-1.0);
  c=c/180.0*PI;
  cout<<a*b*sin(c)/2.0<<endl;
  double cc=a*a+b*b-2*a*b*cos(c);
  cout<<a+b+sqrt(cc)<<endl;
  cout<<b*sin(c)<<endl;
  return 0;
}

