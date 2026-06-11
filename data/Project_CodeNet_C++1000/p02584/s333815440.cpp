#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;

    x = abs(x);
    if (x / d < k) {
        if ((k - x / d) % 2 == 0) {
            cout << x % d << endl;
            return 0;
        } else {
            cout << d - x % d << endl;
            return 0;
        }
    } else {
        cout << x - k * d << endl;
        return 0;
    }
}
