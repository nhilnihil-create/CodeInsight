#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll output = b - a + 1;
    output -= b / c - (a - 1) / c;
    // cout << b / c - (a - 1) / c << endl;
    output -= b / d - (a - 1) / d;
    // cout << b / d - (a - 1) / d << endl;
    // cout << lcm(a, b) << endl;
    output += b / lcm(c, d) - (a - 1) / lcm(c, d);

    cout << output << endl;

    return 0;
}
