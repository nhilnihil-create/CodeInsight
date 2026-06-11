#include<bits/stdc++.h>
using namespace std;

int main(void){
  long double a,b,h,m;cin>>a>>b>>h>>m;
  long double dig=M_PI/180*360*((h+m/60)/12-(m/60));
  printf("%20.20Lf\n",sqrtl(a*a+b*b-2*a*b*cosl(dig)));
  return 0;
}
