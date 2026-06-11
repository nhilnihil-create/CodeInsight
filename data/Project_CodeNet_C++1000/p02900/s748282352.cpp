#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll gcd(ll x, ll y) {
    if (x < y) {
        return gcd(y, x);
    }
    if (y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    ll a, b;
    cin >> a >> b;
    //cout << gcd(a, b) << endl;
    ll x = gcd(a, b);
    ll div = 2;
    ll ret = 1;
    while((x) && (div <= 1000000)) {
        if (x % div == 0) ret++;
        while (x % div == 0) {
            x /= div;
        }
        div++;
    }
    if (x > 1000000) {
        ret++;
    }
    cout << ret << endl;
    return 0;
}