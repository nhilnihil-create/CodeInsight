#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll n; cin >> n;
    ll ans = 0;
    if (n % 2 != 0) {}
    else {
        n /= 2;
        ll q = 5;
        while (q <= n) {
            ans += n / q;
            q *= 5;
        }
    }
    cout << ans << endl;
    return 0;
}