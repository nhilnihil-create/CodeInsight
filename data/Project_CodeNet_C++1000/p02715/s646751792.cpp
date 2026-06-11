#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

const ll MOD = 1000000007;

ll modpow(ll n, ll r) {
    ll p = n;
    ll ret = 1;
    while (r > 0) {
        if (r & 1) ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r >>= 1;
    }
    return ret;
}



int main(){
    ll ans = 0;

    ll N, K;
    cin >> N >> K;

    ll lst[K + 1];
    rep(i, K + 1) lst[i] = 0;

    for (ll k = K; k > 0; --k) {
        ll a = K / k;
        ll tmp = modpow(a, N);
        for (ll j = k; j <= K; j += k) {
            tmp = (MOD + tmp - lst[j]) % MOD;
        }
        ans = (ans + k * tmp) % MOD;
        lst[k] = tmp;
    }
    cout << ans << endl;

    return 0;
}
