#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const double pi = acos(-1);

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double vmax = a*a*b;
    double t = 0, ans = 0;
    if (x > vmax/2) {
        t = vmax - x;
        t *= 2;
        t /= a*a*a;
        ans = atan(t);
        ans *= 180;
        ans /= pi;
    }
    else {
        t = a*b*b;
        t /= 2*x;
        ans = atan(t);
        ans *= 180;
        ans /= pi;
    }
    printf("%.10f\n", ans);
    return 0;
}