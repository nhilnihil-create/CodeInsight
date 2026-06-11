#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
  double a,b,x;scanf("%lf%lf%lf",&a,&b,&x);
  double c = x/b*2/a;
  double d = (a*a*b-x)/a*2/a;
  if(x*2 <= a*a*b) printf("%lf\n",atan(b/c)*180/M_PI);
  else printf("%lf\n",double(90)-atan(a/d)*180/M_PI);
}