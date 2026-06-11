#include <bits/stdc++.h>
using namespace std;
//解説AC
double PI=acos(-1);
int main() {
  double a,b,x,rad,kotae;
  cin>>a>>b>>x;
  double ryou=x/a;
  if(2*ryou>=a*b){
    double h=(a*b-ryou)*2/a;
    rad=atan2(h,a);
  }else{
    double w=ryou*2/b;
    rad=atan2(b,w);
  }
  kotae=rad/(2*PI)*360;
  cout<<fixed<<setprecision(12)<<kotae<<endl;
  return 0;
}