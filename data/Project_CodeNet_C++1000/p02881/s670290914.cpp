#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll ans = 1001001001001001001;
    for (ll a = 1; a * a <= n; ++a) {
        if (n % a == 0) {
            ll b = n / a;
            ans = min(ans, a + b - 2);
        }
    }
    cout << ans << endl;
}
