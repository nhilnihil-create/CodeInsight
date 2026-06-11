#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    ll n, k; cin >> n >> k;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    ll comb = (k * (k - 1) / 2) % MOD;
    for(int i = 0; i < n; i++){
        ll be = 0, af = 0;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]) be++;
        }
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[i]) af++;
        }
        ans = (ans + (k * af) + (comb * (be + af))) % MOD;
    }
    cout << ans << endl;

    return 0;
}
