#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);

    ll times = x / d;
    if(times > k) {
        cout << x - k*d << endl;
        return 0;
    }

    x -= times * d;
    k -= times;
    k %= 2;
    if(k&1) x -= d;
    cout << abs(x) << endl;
}
