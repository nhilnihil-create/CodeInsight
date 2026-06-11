#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll fact[N], inv_fact[N];
const ll mod = 1e9 + 7;
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll fp(ll base, ll pw) {
    if (pw == 1) return base;
    if (base == 0) return 0;
    if (pw == 0) return 1;
    ll x = fp(base, pw / 2);
    x = mul(x, x);
    if (pw & 1) x = mul(x, base);
    return x;
}
void build() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(i, fact[i - 1]);
        inv_fact[i] = fp(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r) {
    if (r > n) return 0;
    ll A = fact[n];
    ll B = mul(inv_fact[r], inv_fact[n - r]);
    return mul(A, B);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    build();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cout << mul(ncr(n - k + 1, i), ncr(k - 1, i - 1)) << '\n';
    return 0;
}