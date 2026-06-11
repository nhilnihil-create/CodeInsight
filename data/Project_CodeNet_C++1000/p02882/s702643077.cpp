#include <bits/stdc++.h>
using namespace std;

int main(){
 double a,b,x;
  cin>>a>>b>>x;
  double ta=2*(-x/(a*a*a)+b/a);
  if(ta<=b/a) {
    printf("%.10lf\n",atan(ta)/(2*3.141592653589)*360.0);
    return 0;
  }
  ta=a*b*b/(2*x);
  printf("%.10lf\n",atan(ta)/(2*3.141592653589)*360.0);
}