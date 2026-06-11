#include <bits/stdc++.h>

using namespace std;

int main() {
    double A, B, H, M;
    cin >> A >> B >> H >> M;

    double alpha = (H * 60 + M) / 720 * (M_PI * 2);
    double beta = (M / 60) * (M_PI * 2);
    double theta = alpha - beta;
    double ans = sqrt(A * A + B * B - 2 * A * B * cos(theta));
    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}