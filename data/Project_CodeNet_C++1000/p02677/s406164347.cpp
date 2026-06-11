#include <bits/stdc++.h>


using namespace std;


int main(void) {
    double A, B, H, M;
    cin >> A >> B >> H >> M;
    double ha = 2 * M_PI * (H / 12) + (2 * M_PI / 12) * (M / 60);
    double ma = 2 * M_PI * (M / 60);
    double x;
    if (ha >= ma) {
        x = ha - ma;
    } else {
        x = ma - ha;
    }
    if (x > M_PI) {
        x = 2 * M_PI - x;
    }
    double ans = sqrt(A * A + B * B - 2 * A * B * cos(x));
    printf("%.16f\n", ans);
}
