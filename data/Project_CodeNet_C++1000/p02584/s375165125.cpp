#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    ll a = abs(x) / d;
    if (a >= k) {
        cout << abs(x) - d * k << '\n';
    } else {
        k -= a;
        if (k % 2 == 0) {
            cout << abs(x) - d * a << '\n';
        } else {
            cout << abs(abs(x) - d * (a + 1)) << '\n';
        }
    }
}