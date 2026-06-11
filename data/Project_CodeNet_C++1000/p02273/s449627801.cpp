#include <iostream>
#include <cmath>
using namespace std;

static const double pi = 3.141592653589793;

void koch(int n, double *p1, double *p2) {
    if(n==0) {
        return;
    }

    double s[2], t[2], u[2];

    //sのx座標、y座標を計算する
    s[0] = (2 * p1[0] + 1 * p2[0]) / 3;
    s[1] = (2 * p1[1] + 1 * p2[1]) / 3;
    //tのx座標、y座標を計算する
    t[0] = (1 * p1[0] + 2 * p2[0]) / 3;
    t[1] = (1 * p1[1] + 2 * p2[1]) / 3;
    //uのx座標、y座標を計算する
    u[0] = (t[0] - s[0]) * cos(pi/3) - (t[1] - s[1]) * sin(pi/3) + s[0];
    u[1] = (t[0] - s[0]) * sin(pi/3) + (t[1] - s[1]) * cos(pi/3) + s[1];

    koch(n-1, p1, s);
    cout << s[0] << " " << s[1] << endl;
    koch(n-1, s, u);
    cout << u[0] << " " << u[1] << endl;
    koch(n-1, u, t);
    cout << t[0] << " " << t[1] << endl;
    koch(n-1, t, p2);
}

int main() {
    int n;
    double p1[2], p2[2];
    p1[0] = 0.0;
    p1[1] = 0.0;
    p2[0] = 100.0;
    p2[1] = 0.0;
    cin >> n;
    cout << p1[0] << " " << p1[1] << endl;
    koch(n, p1, p2);
    cout << p2[0] << " " << p2[1] << endl;

    return 0;
}
