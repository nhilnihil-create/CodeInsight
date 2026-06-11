#include <bits/stdc++.h>
using namespace std;
const double Rad_to_deg=45.0/atan(1.0);
int main() 
{
    double a,b,h,m;cin>>a>>b>>h>>m;
    double x=abs(6*m-30*h-m/2)/Rad_to_deg;
    double ans=sqrt(a*a+b*b-2*a*b*cos(x));
   // 4.56425719433005567605
    printf("%.20f",ans);
}


