#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long double a, b, x;
    cin >> a >> b >> x;
    long double y = x/(a*a);
    long double theta;
    long double ans;

    if(2 * x >= a*a*b){
        theta = atan((2*b - 2*y)/a);
        ans = theta * 180 /M_PI;
    }
    else{
        long double c = 2*a*y/b;
        theta = atan(b/c);
        ans = theta * 180 / M_PI;
    }
    printf("%.10Lf\n", ans);
    return 0;
}