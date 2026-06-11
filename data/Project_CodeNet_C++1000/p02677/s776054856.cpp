#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,h,m;
  cin>>a>>b>>h>>m;
  double p=0.5*m+30*h;
  int q=6*m;
  double kakudo=min(360-abs(p-q),abs(p-q));
  double t=cos(kakudo*M_PI/180);
  cout<<fixed<<setprecision(15)<<sqrt(a*a+b*b-2*a*b*t)<<endl;
  return 0;
}
