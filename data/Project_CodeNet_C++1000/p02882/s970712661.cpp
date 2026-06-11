#include <bits/stdc++.h>
using namespace std;
int main(void){
    long double a,b,x;
    long double pi=3.141592653589793;
    cin>>a>>b>>x;
    if (x<=a*a*b/2) {
        long double tmp=x*2/(a*b);
        long double ans=acosl(b/sqrt(tmp*tmp+b*b))*(180.0/pi);
        printf("%.10Lf\n",90.0-ans);
    } else {
        long double tmp=(2*a*a*b-2*x)/(a*a);
        long double ans=acosl(a/sqrt(a*a+tmp*tmp))*(180.0/pi);
        printf("%.10Lf\n",ans);
    }
}