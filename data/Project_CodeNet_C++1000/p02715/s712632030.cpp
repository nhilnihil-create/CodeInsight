#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1000000007;

ll beki(ll x, ll n, const ll &p) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll cnt[101010];
    for (int i = k; i > 0; i--) {
        ll num = beki(k / i, n, mod);
        for (int j = i * 2; j <= k; j += i) {
            num -= cnt[j];
        }
        cnt[i] = num;
        ans = (ans + num * i) % mod;
    }
    ans += mod;
    ans %= mod;
    cout << ans << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
