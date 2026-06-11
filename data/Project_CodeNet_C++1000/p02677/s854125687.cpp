#include <bits/stdc++.h>
using namespace std;
# define LL long long

int main(){
    double a,b,h,m, x;
    scanf("%lf%lf%lf%lf",&a,&b,&h,&m);
    double y=m/2;
    if (h*5>=m){
        x=((h*5)-m)*6+y;
    }
    else{
        x=(m-(h*5))*6-y;
    }
    double ans=sqrt((a*a)+(b*b)-(2*a*b*cos(x* M_PI /180.0)));
    printf("%17.13f",ans);
}