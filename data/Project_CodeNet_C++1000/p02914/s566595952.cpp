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
void hakidashi(vector<ll>& v) {
    int pos = 0;
    for (int d = 60; d >= 0; d--) {
        int add = 0;
        for (int i = pos; i < sz(v); i++) {
            if (!(v[i] >> d & 1)) continue;
            add = 1;
            swap(v[pos], v[i]);
            break;
        }

        for (int i = pos + 1; i < sz(v); i++) {
            if (v[i] >> d & 1) v[i] ^= v[pos];
        }
        pos += add;
    }
}
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<int> cnt(62);
    rep(i, n) rep(d, 62) cnt[d] ^= (a[i] >> d & 1);
    ll ans = 0;
    rep(d, 62) {
        if (cnt[d]) {
            ans += 1ll << d;
            rep(i, n) {
                a[i] &= ~(1ll << d);
            }
        }
    }
    hakidashi(a);
    ll add = 0;
    for (ll x : a) {
        for (int d = 62; d >= 0; d--) {
            if (x >> d & 1) {
                if (!(add >> d & 1)) add ^= x;
                break;
            }
        }
    }
    ans += 2 * add;
    cout << ans << endl;
}