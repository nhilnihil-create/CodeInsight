#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    if (__int128(k) * d <= x) {
        cout << x - k * d << endl;
    } else {
        k = k - x / d;
        x -= (x / d) * d;
        k = k % 2;
        cout << abs(x - k * d) << endl;
    }
}
