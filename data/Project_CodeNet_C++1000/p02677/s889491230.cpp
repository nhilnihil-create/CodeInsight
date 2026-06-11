#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    using ldouble = long double;
    const ldouble pi = 4 * atan(1.0);
    ldouble A, B, H, M;
    cin >> A >> B >> H >> M;
    ldouble ang_a = 2.0 * pi * (H/12.0 + M/(12.0 * 60.0));
    ldouble ang_b = 2.0 * pi * (M/60.0);
    ldouble ang = abs(ang_a - ang_b);
    cout << setprecision(20);
    cout << sqrt(A*A + B*B - 2.0 * A * B * cos(ang)) << '\n'; 
}
