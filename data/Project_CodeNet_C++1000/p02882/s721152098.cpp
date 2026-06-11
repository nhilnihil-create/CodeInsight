#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,x; cin >> a >> b >> x;
    double theta;

    if(x+0.0 > a*a*b/2.0) {
        theta = atan(2.0*(a*a*b-x)/(double)(a*a*a));
    }else{
        theta = atan((double)(a*b*b)/(2.0*x));
    }
    
    double ans = theta*180.0/(acos(-1));
    printf("%.8lf", ans);
    return 0;
}
