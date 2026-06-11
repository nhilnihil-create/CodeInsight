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
ll com[2000009];
ll comb_l(ll n, ll k) {
    if (com[k] != 0) return com[k];
    com[0] = 1;
    reps(i, k) { com[i] = ((((n - i + 1) * modinv(i)) % M) * com[i - 1]) % M; }
    return com[k];
}
int x, y;

int main() {
    cin >> x >> y;
    int n = (x + y) / 3;
    if ((x + y) % 3 == 0 && n <= x && x <= n * 2 && n <= y && y <= n * 2) {
        cout << comb_l(n, x - n) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}