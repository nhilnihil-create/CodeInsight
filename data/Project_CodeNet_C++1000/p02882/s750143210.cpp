#include <iostream>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES

using namespace std;
int a,b,n;

int main()
{
    scanf("%d%d%d",&a,&b,&n);
    double mx = a*b*a/2.0, ans;
    if(mx>=n){
        double da = 1.0*n/b/a*2;
        ans = 90 - atan(da/b)*180/M_PI;
    }else if(mx<n){
        double x = 2.0*n/a/a-b;
        ans = 90 - atan(a/(b-x))*180/M_PI;
    }
    printf("%.9lf\n",ans);
    return 0;
}
