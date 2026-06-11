#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    if (x/d >= k) {
        x = x - k*d;
        cout << x;
        return 0;
    }
    long long s = x / d;
    x = x % d;
    k = k - s;
    if (k % 2 == 0) {
        cout << x; 
    } else {
        cout << d - x; 
    }
}
