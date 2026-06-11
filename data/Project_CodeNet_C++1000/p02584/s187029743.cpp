#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll x, k, d, n;
    cin >> x >> k >> d;
    if (x < 0) {x *= -1;}

    n = x / d;
    if (k >= n) {
        k -= n;
        x %= d;
    }
    else {
        x -= d * k;
        k = 0;
    }
    if (k % 2 == 1) {x = d - x;}

    cout << x << endl;
}
