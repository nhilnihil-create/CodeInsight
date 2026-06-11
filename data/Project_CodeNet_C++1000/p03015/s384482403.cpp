#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

ll modpow(ll a, int n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            (res *= a) %= MOD;
        (a *= a) %= MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string L;
    cin >> L;

    int N = L.length();
    ll pow2 = 1, pow3 = modpow(3, N);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        (pow3 *= 333333336) %= MOD;
        if (L[i] == '0')
            continue;
        ans += pow2 * pow3 % MOD;
        ans %= MOD;
        (pow2 *= 2) %= MOD;
    }
    ans += pow2;

    cout << ans % MOD << endl;

    return 0;
}
