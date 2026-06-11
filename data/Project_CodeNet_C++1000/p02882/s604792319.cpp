#include <iostream>
#include <cmath>
#include <iomanip>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double v = a * a * b;
    double ans = 0;
    if(x < v/2) {
        ans = atan((a*b*b)/(2*x));
    } else {
        if(v != x) {
            ans = atan((2*(v-x)) / (a*a*a));
        }
    }
    ans *= (double)180/M_PI;
    cout << fixed << setprecision(10);
    cout << ans << endl;

    return 0;
}
