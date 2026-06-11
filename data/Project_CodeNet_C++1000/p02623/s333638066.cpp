#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (int i = 0; i < sz(v); i++) {
        os << v[i];
        if (i < sz(v) - 1) os << " ";
    }
    return os;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vector<ll> sa(n + 1), sb(m + 1);
    rep(i, n) sa[i + 1] = sa[i] + a[i];
    rep(i, m) sb[i + 1] = sb[i] + b[i];

    int ans = 0;
    rep(i, n + 1) {
        if (sa[i] > k) break;
        int now = i;
        now += (--upper_bound(all(sb), k - sa[i])) - sb.begin();
        chmax(ans, now);
    }
    cout << ans << endl;
}