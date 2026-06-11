#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
  int a,b,c;
  double S,l,h,d;
  cin>>a>>b>>c;
  d=(acos(-1)*c)/180;
  S=a*b*sin(d)/2;
  l=a+b+sqrt(a*a+b*b-2*a*b*cos(d));
  h=b*sin(d);

  printf("%lf\n%lf\n%lf\n",S,l,h);
    
  return 0;
}
    

