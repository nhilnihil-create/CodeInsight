#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const long double PI = acos(-1);
const long double EPS = 0.0000000001;

long double calc_volume(long double a, long double b, long double theta) {
    if(theta > PI / 2.0 - EPS) return 0.0;

    if (a * tan(theta) >= b) {
        return a * b * b / tan(theta) / 2.0;
    } else {
        return a * a * b - a * a * a * tan(theta) / 2.0;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int a, b, x;
    cin >> a >> b >> x;

    long double l = 0.0, r = PI / 2.0;
    for(int _ = 1; _ <= 100000; _++) {
        long double mid = (l + r) / 2.0;
        if(calc_volume(a, b, mid) < x) r = mid;
        else l = mid;
    }
    long double ans = 180 * r / PI;
    printf("%.10Lf\n", ans);
}