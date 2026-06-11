#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 998244353;

ll powmod(ll a, ll x) {
    ll ret = 1;
    for (ll i = 0; i < x; i++) {
        ret = (ret * a) % MOD;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    ll d, ans = 1;
    vector<ll> cnt(n);
    cin >> d;
    if (d) ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> d;
        cnt[d]++;
    }
    if (cnt[0]) ans = 0;
    cnt[0] = 1;
    // bool zero = false;
    for (int i = 1; i < n; i++) {
        // if (zero) {
        //     if (cnt[i]) ans = 0;
        // } else if (cnt[i] == 0) {
        //     zero = true;
        // } else {
        ans = (ans * powmod(cnt[i - 1], cnt[i])) % MOD;
        // }
    }
    cout << ans << endl;
    return 0;
}