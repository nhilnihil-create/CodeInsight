#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  double a,b,x;
  cin >> a>>b>>x;
  double y,ans,arc,aa;
  if(a*a*b/2<=x){
    y=2*b-2*x/(a*a);
    ans=y/a;
    arc=atan(ans);
    aa=arc*180/M_PI;
  }else{
    y=2*x/(a*b);
    ans=b/y;
    arc=atan(ans);
    aa=arc*180/M_PI;
  }
  printf("%.10lf",aa);
}
    