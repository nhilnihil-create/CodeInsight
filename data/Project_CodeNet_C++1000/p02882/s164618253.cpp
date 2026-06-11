#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const double pi = acos(-1);

int main() {
    double a, b, x; cin >> a >> b >> x;
    if (2*x > a*a*b){
        double h = (2.0*(a*a*b - x)) / (a*a);
        //cout << h << endl;
        double rad = atan2(h, a);
        double ans = (rad*180.0) / acos(-1);
        printf("%.10f\n", ans);
    } else {
        double d = (2.0*x) / (a*b);
        //cout << d << endl;
        double rad = atan2(b, d);
        double ans = (rad / pi) * 180.0;
        printf("%.10f\n", ans);
    }
    return 0;
}