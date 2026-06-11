#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

ll const MAX = 3e+5;
ll const D = 64;
ll const MOD = (ll)1e+9 + 7;
P table[MAX+1][D];

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    for (ll i = N-1; i >= 0; i--) {
        ll t = A[i];
        ll j = 0;
        while (j < D) {
            ll a = t & 1;
            ll zero = table[i+1][j].first;
            ll one = table[i+1][j].second;
            if (a) one++;
            else zero++;
            table[i][j] = {zero, one};
            j++;
            t /= 2;
        }
    }


    ll ans = 0;
    rep(i, N) {
        rep(j, D) {
            if ((A[i]>>j) & 1ll) {
                ans += (((1ll << j) % MOD) * (ll)table[i][j].first) % MOD;
                ans %= MOD;
            } else {
                ans += (((1ll << j) % MOD) * (ll)table[i][j].second) % MOD;
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;

    return;
}


int main() {
    solve();
    return 0;
}
