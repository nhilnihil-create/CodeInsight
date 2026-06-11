#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    V<ll> sums(n + 1);
    for(int i = 0; i < n; i++){
        sums[i + 1] = sums[i] + a[i];
    }

    ll ans = INF;
    for(int i = 1; i <= n; i++){
        ll x = sums[i];
        ll y = sums[n] - sums[i];
        ans = min(ans, abs(y - x));
    }
    cout << ans << endl;


    return 0;
}
