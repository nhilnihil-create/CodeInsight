#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double S = x / a;
    if(S == a * b / 2) {
        cout << 45 << endl;
    } else if(S < a * b / 2) {
        cout << fixed << setprecision(6)
             << (360 / (2 * M_PI)) * atan((b * b) / (2 * S)) << endl;
    } else if(S > a * b / 2) {
        cout << fixed << setprecision(6)
             << (360 / (2 * M_PI)) * atan(2 * (a * b - S) / (a * a)) << endl;
    }
    return 0;
}