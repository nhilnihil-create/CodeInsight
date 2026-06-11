#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long x, k, d; cin >> x >> k >> d;
    x = abs(x);
    long long p = min(k, x / d);
    x -= p * d; k -= p;
    if (k % 2 == 0) {
        cout << x << endl;
    }
    else {
        cout << d - x << endl;
    }
    return 0;
}

