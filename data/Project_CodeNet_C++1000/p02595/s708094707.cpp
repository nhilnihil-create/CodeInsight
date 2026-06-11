#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, d, r = 0; cin >> n >> d;
    while (n--) {
        ll x, y; cin >> x >> y;
        r += (x * x + y * y <= d * d);
    }
    cout << r << endl;
    return 0;
}
