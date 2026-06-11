#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793

int main(){
    double a,b,x;
    cin >> a >> b >> x;
    // double h = x / a*a ;
    double ans;
    if(a * a * b / 2.0 <= x) {
        ans = atan(2 * (a * a * b - x) / (a * a * a));
    } else {
        ans = PI / 2 - atan(2 * x / (a * b * b));
    }
    cout << setprecision(10) << ans*(180/PI) << endl;
    return 0;
}