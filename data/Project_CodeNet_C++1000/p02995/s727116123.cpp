#include <iostream>
#include <iomanip>

typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for(ll i=init;i<(n);i++)

ll gcd(ll a, ll b) {
    if (b > a)swap(a, b);
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll cd = gcd(c, d);
    cout << b - (a - 1)
            - b / c + (a - 1) / c
            - b / d + (a - 1) / d
            + b / (c * d / cd)
            - (a - 1) / (c * d / cd) << endl;
    return 0;
}
