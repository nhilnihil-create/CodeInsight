#include <bits//stdc++.h>
using namespace std;
typedef long long int ll;
int main(void) {
    ll t1, t2, a1, a2, b1, b2; cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll p = (a1 - b1) * t1, q = (a2 - b2) * t2;
    if (p >= 0) p *= -1, q *= -1;
    if (p + q < 0) cout << 0 << endl;
    else if (p + q == 0) cout << "infinity" << endl;
    else {
        ll s = -p / (p + q), t = -p % (p + q);
        if (t != 0) cout << s * 2 + 1 << endl;
        else cout << s * 2 << endl;
    }
}