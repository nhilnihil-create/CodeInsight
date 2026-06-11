#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

int main() { 
    ll A, B, H, M;
    cin >> A >> B >> H >> M;
    ll angle = 0;
    ll out = 0;
    angle = fabs((M_PI / 6 * H + M_PI*M / 360) - (M_PI * M / 30));
    out = sqrt(A * A + B * B - 2 * A * B * cos(angle));
    cout << fixed << setprecision(9) << out << endl;
    return 0;
}