#include <bits/stdc++.h>
using namespace std;


void solve(double a, double b, double x){
    double rad;
    double s = x/a;
    if(s <= a*b/2){
        rad = atan2(b, 2*s/b);
    }else
    {
        rad = atan2((2*(a*b-s)/a), a);
    }
    double PI = acos(-1);
    double deg = rad/(2*PI) * 360;
    printf("%.10f\n", deg);
    return;
}

int main(){
    double a, b, x;
    cin >> a >> b >> x;
    solve(a, b, x);
    return 0;
}
