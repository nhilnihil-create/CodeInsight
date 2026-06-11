#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    int a,b,x; cin >> a >> b >> x;

    double rad;
    if(a*a*b >= 2*x){
        rad = atan2(a*b*b, 2*x);
    }else{
        rad = atan2(2*a*a*b - 2*x,a*a*a);
    }
    double deg = 180 * rad / M_PI;
    cout << std::setprecision(10) << deg << endl;
}