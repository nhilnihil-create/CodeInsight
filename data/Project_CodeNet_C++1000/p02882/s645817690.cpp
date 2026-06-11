#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double ma;
    double ans;
    if(a * b / 2 * a < x) {
        ma = x / a  / a * 2 - b;
        ans = 90 - atan(a / (b - ma)) * 180 / M_PI;
    }
    else{
        ma = x / a * 2 / b;
        ans = 90 - atan(ma / b) * 180 / M_PI;
    }
    printf("%.10lf\n",ans) ;
}