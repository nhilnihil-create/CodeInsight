#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

#define M 1'000'000'007
ll factorial[200'002];

ll modfact(ll num) {
    if (num == 0) {
        return 1;
    }
    if (num <= 2) {
        return num;
    }
    if (factorial[num] != 0) {
        return factorial[num];
    }
    return factorial[num] = (modfact(num - 1) * num) % M;
}
ll mod_power(ll x, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        return mod_power((x * x) % M, n / 2);
    } else {
        return (mod_power((x * x) % M, n / 2) * x) % M;
    }
}
ll modinv(ll a) {
    ll b = M, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= M;
    if (u < 0) u += M;
    return u;
}

ll comb(ll n, ll k) { return (((modfact(n) * modinv(modfact(k))) % M) * modinv(modfact(n - k))) % M; }

ll com[2000009];
ll comb_l(ll n, ll k) {
    if (com[k] != 0) return com[k];
    com[0] = 1;
    reps(i, k) { com[i] = ((((n - i + 1) * modinv(i)) % M) * com[i - 1]) % M; }
    return com[k];
}

int n, a, b;
int main() {
    cin >> n >> a >> b;
    ll ans = mod_power(2, n) - 1;
    ans = (ans - comb_l(n, b) >= 0) ? (ans - comb_l(n, b)) % M : (ans - comb_l(n, b) + M) % M;
    ans = (ans - comb_l(n, a) >= 0) ? (ans - comb_l(n, a)) % M : (ans - comb_l(n, a) + M) % M;
    cout << ans << endl;
    return 0;
}
