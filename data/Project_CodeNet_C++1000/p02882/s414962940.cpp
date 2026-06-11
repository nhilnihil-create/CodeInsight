#include<bits/stdc++.h>
typedef long double ld;
using namespace std;
int main(void){
  ld a,b,x; cin>>a>>b>>x; x/=a;
  ld dig;
  if((x*2)==(a*b)){ printf("%.10llf\n",(long double)45); return 0;}
  else if(x*2<a*b){
    a=2*x/b;
    ld c=sqrtl(a*a+b*b);
    dig=asin(b/c);
  }else{
    b=2*(a*b-x)/a;
    ld c=sqrtl(a*a+b*b);
    dig=acos(a/c);
  }
  printf("%.10llf\n",dig*180/M_PI);
  return 0;
}