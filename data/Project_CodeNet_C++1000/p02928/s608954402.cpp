#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

ll sum(ll x) {
    ll ret = x * (x + 1) / 2;
    ret %= MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; 
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll bef = 0, loop = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) {
                if (j > i) {
                    bef++;
                }
                loop++;
            }
        }
        ans += (bef * k) % MOD; ans %= MOD;
        ans += (loop * sum(k - 1)) % MOD; ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}