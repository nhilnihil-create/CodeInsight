#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    long long p = (a1 - b1) * t1, q = (a2 - b2) * t2;
    if (p > 0) {
        p *= -1;
        q *= -1;
    }

    if (p + q < 0) cout << 0 << endl;
    else if (p + q == 0) cout << "infinity" << endl;
    else {
        if (-p % (p + q) == 0) cout << -p / (p + q) * 2 << endl;
        else cout << 1 + -p / (p + q) * 2 << endl;
    }
}