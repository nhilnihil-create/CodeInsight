#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double theta = ((h + m / 60.0) * 30 - m * 6) * (double)(acos(-1)) / 180.0;
    double ans = sqrt(a * a + b * b - 2 * a * b * cos(theta));
    cout << setprecision(20) << ans << endl;
    return 0;
}