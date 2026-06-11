#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {

    ll x, k, d;
    cin >> x >> k >> d;
    if(x < 0) x = -x;
    if(x/d >= k) {
        return printf("%lld", x - d*k) * 0;
    }
    ll temp = x/d, remain = k - x/d;

    if(remain&1) cout << abs(x - temp*d - d);
    else cout << (x - temp*d);

    return 0;
}
