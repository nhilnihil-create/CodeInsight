#include <bits/stdc++.h>
using namespace std;
int a, b, x;
const double PI = acos(-1);


int main() {
    double a,b,x; cin >> a >> b >> x;
    x /= a;
    auto f=[&](double t){
        if (tan(t)<=b/a) return a*b - (a*a*tan(t))/2;
        else return b*(b/tan(t))/2;
    };
    double ok = 0.0;
    double ng = PI/2.0; 
    for (int i=0; i< 100; ++i){
        double theta = (ok + ng)/2;
        if (f(theta) >= x) ok = theta;
        else ng = theta;
    }
    cout << fixed << setprecision(10) << ok * 180 / PI << endl;
    // cout << fixed << setprecision(8) << (a*a*b - (a*a*a*tan((double)PI/3.9))/2 - x) << endl; 
}
