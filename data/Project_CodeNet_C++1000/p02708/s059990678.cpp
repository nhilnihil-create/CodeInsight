#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    const ll mod = 1000000007;
    ll n, k; cin >> n >> k;
    ll ans = 0;
    for (ll i = k; i <= n + 1; i++) {
        ll tmpLeft = (i - 1) * i / 2;
        ll tmpRight = n * (n + 1) / 2 - (n - i) * (n - i + 1) / 2;
        ans+= tmpRight - tmpLeft + 1;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}