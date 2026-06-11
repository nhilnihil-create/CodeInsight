#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    ll t1, t2, a1, a2, b1, b2; cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    a1 *= t1;
    b1 *= t1;
    a2 *= t2;
    b2 *= t2;

    if (a1 + a2 == b1 + b2) {
        cout << "infinity" << endl;
        return 0;
    }

    if (a1 + a2 > b1 + b2) {
        if (a1 > b1) {
            cout << 0 << endl;
        } else {
            ll c = abs(a1 - b1);
            ll d = abs((a1 + a2) - (b1 + b2));
            if (c % d == 0) {
                cout << (c + d - 1) / d * 2 << endl;
            } else {
                cout << (c + d - 1) / d * 2 - 1 << endl;
            }
        }
    } else {
        if (b1 > a1) {
            cout << 0 << endl;
        } else {
            ll c = abs(a1 - b1);
            ll d = abs((a1 + a2) - (b1 + b2));
            if (c % d == 0) {
                cout << (c + d - 1) / d * 2 << endl;
            } else {
                cout << (c + d - 1) / d * 2 - 1 << endl;
            }
        }
    }

    return 0;
}