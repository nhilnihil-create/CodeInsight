#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

const double PI = 3.14159265358979;

int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double s = x / a;
    double ans;
    if (s > a * b / 2){
        double t = 2 * s / a - b;
        double theta = atan(a/(b-t));
        ans = 90 - theta * 180 / PI;
    }
    else{
        double t = 2*s/b;
        double theta = atan(t/b);
        ans = 90 - theta * 180 / PI;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}