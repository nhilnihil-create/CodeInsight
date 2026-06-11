#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
const ll mod = 1e9 + 7;

ll solve(ll l, ll r) {
    ll n = r - l + 1;
    return n * (2*l + (n-1)) / 2;
}

ll add(ll a, ll b) {
    return (a+b)%mod;
}

ll sub(ll a, ll b) {
    return (a - b + mod) % mod;
}
int main() {
    fastIO;
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = k; i <= n+1; i++) {
        ll x = solve(0, i-1);
        ll y = solve(n - i + 1, n);
        //cout << x << ' ' << y << endl;
        ans = add(ans, sub(y, x));
        ans = add(ans, 1);
    }
    cout << ans;
}