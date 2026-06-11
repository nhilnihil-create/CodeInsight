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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string L;
    cin >> L;

    ll pow2 = 1, pow3 = 1;
    for (int i = 0; i < L.length(); ++i)
        (pow3 *= 3) %= MOD;

    ll ans = 0;
    for (int i = 0; i < L.length(); ++i) {
        (pow3 *= 333333336) %= MOD;
        if (L[i] == '0')
            continue;
        (ans += pow2 * pow3 % MOD) %= MOD;
        (pow2 *= 2) %= MOD;
    }
    (ans += pow2) %= MOD;

    cout << ans << endl;

    return 0;
}
