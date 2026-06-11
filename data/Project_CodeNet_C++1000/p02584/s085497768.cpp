#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    ll x, k, d;
    cin >> x >> k >> d;
    
    x = x > 0 ? x : -x;

    ll temp = min(k, x / d);
    k -= temp;
    x -= temp * d;
    if (k > 0 && k % 2 == 1) {
        x -= d;
    }

    cout << abs(x);

    return 0;
}