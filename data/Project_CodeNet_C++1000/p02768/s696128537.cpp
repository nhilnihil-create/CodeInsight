#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const ll mod = 1e9 + 7;

ll my_pow(ll n, ll m) {
    if (m == 0) return 1;
    ll now = my_pow(n, m / 2);
    if (m % 2 == 0) return (now * now) % mod;
    else return (((now * now) % mod) * n) % mod;
}

ll fact(ll n) {
    if (n == 0) return 1;
    return (n * fact(n - 1)) % mod;
}

ll C(ll n, ll k) {
    ll now = 1;
    for (int i = n; i >= n - k + 1; i--) {
        now *= i;
        now %= mod;
    }
    return (now * my_pow(fact(k), mod - 2)) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    cout << (my_pow(2, n) - 1 - C(n, a) - C(n, b) + 3 * mod) % mod;
    return 0;
}
