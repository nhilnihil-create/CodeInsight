#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    double ans = 0;
    if (x == 2) {
        cout << "0.5000000000" << "\n";

    } else if (x % 2 == 0) {
        double bb = x / 2;
        ans = (bb / x);
        cout << fixed << setprecision(6) << ans << "\n";


    } else if (x % 2 != 0) {
        double aa = ((x / 2) + 1);
        ans = (aa / x);
        cout << fixed << setprecision(6) << ans << "\n";

    }

}













