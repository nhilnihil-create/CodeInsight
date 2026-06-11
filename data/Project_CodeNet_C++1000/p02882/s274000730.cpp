#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
double pi = 2.0 * asin(1.0);    /* πの値. */

int main() {
    double a, b, x;
    cin >> a >> b >> x;

    double s = a*a*b/2;    /* 三角柱での最大体積. */
    int d=1;        /* 1:sankaku. */
    if(x > s) d=0;  /* 0:daikei. */

    double radian;
    double degree;
    /* sankaku. */

    if (d == 1) {
        //cout << "sankaku" << endl;
        /* 体積x = a * ac * b / 2. */
        double ac = x*2 / (b*a);
        radian = atan2(ac, b);
        degree = 90.0 - (radian * 180.0 / pi);
    } else {
        //cout << "daikei" << endl;
        /* 体積x = ((bc+b)*a / 2) * a. */
        double bc = (2*x)/(a*a) - b;
        /* 台形じゃない側の三角形は、縦(b-bc), 横(a). */
        radian = atan2(a, b-bc);
        degree = 90 - (radian * 180.0 / pi);
    }

    cout << fixed << setprecision(10) << degree << endl;

	return 0;
}
