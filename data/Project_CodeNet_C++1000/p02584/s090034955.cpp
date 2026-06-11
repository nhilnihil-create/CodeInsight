#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x, k, d;
    cin >> x >> k >> d;

    x = abs(x);
    long long f = min(k,x/d);
    k -= f;
    x -= f * d;
    if (k % 2 == 0)
        cout << x << endl;
    else
        cout << d - x << endl;
}

