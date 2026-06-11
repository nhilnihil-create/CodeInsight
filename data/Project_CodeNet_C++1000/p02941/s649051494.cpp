#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    priority_queue<pair<ll, ll>> pq;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        cin >> b[i];
        if(b[i] > a[i]) pq.push({b[i], i});
    }
    ll ans = 0;
    while(!pq.empty()) {
        ll i = pq.top().second;
        ll x = pq.top().first;
        pq.pop();
        ll y = b[(i + n - 1) % n] + b[(i + 1) % n];
        ll z = x % y;
        if(a[i] % y == z) {
            ans += (x - a[i]) / y;
            b[i] = a[i];
        } else if(x == z || a[i] > z) {
            cout << -1 << endl;
            return 0;
        } else {
            ans += x / y;
            b[i] = z;
            pq.push({z, i});
        }
    }

    cout << ans << endl;

    return 0;
}