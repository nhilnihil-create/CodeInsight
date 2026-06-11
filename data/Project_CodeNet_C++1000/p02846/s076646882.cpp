#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll t1, t2, a1, a2, b1, b2, c1 = 0, c2 = 0, z = 0;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
        cout << "infinity";
        return 0;
    }
    ll x = 0, y = 0;
    bool l = 0;
    for (int i = 1; i <= 200; i++) {
        c1 += t1 * a1;
        c2 += t1 * b1;
        //cout << c1 - c2 << '\n';
        if (!x) x = c1 - c2;
        int k;
        if (c1 - c2 < 0) k = 1;
        else k = 0;
        if ((i > 1 && k != l) || c1 == c2) z++;
        l = k;
        c1 += t2 * a2;
        c2 += t2 * b2;
        //cout << c1 - c2 << '\n';
        if (!y) y = c1 - c2;
        if (c1 - c2 < 0) k = 1;
        else k = 0;
        if (k != l || c1 == c2) z++;
        l = k;
        //break;
    }
    //cout << z << '\n';
    //cout << x << ' ' << y << ' ';
    if ((x > 0 && y > 0) || (x < 0 && y < 0)) cout << 0;
    else {
        if (abs(x) % abs(y) == 0) cout << abs(x) / abs(y) * 2;
        else cout << abs(x) / abs(y) * 2 + 1;
    }
}
