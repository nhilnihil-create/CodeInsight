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
    ll k;
    cin >> k;
    int rem = 0;
    rep(i, k + 1) {
        rem = (rem + beki(10, i, k) * 7) % k;
        if (rem == 0) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}