#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << #x << "]: " << (x) << endl;

constexpr ll MOD = 1e9+7;
ll bin_pow(ll a, ll b) {
    ll ans = 1;
    for ( ; b>0; b/=2) {
        if (b&1) ans = ans*a % MOD;
        a = a*a % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if (n == 1) cout << "0\n";
    else {
        ll ans = bin_pow(10, n) - 2 * bin_pow(9, n) + bin_pow(8, n);
        ans = (ans % MOD + MOD) % MOD;
        cout << ans << "\n";
    }
}
