#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double kaku1 = (60 * h + m) / 60 * 2 * M_PI;
    double kaku2 = (60 * h + m) / 720 * 2 * M_PI;
    cout << fixed << setprecision(10)
         << sqrt(a * a + b * b - 2 * a * b * cos(kaku1 - kaku2)) << endl;
    ;
    return 0;
}