#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,h,k;
  cin >> a >> b >> h >> k;
  long double rad=((long double)h/12.0+((long double)k/60.0)/12.0-(long double)k/60.0);
  long double ans=(long double)sqrt(a*a+b*b-(long double)2.0*a*b*cos(2*rad*M_PI));
  printf("%.10Lf",ans);
}
  
              