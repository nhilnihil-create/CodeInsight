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
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
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

int main() {
    int k, q;
    cin >> k >> q;
    vector<ll> d(k);
    rep(i, k) cin >> d[i];
    while (q--) {
        ll n, x, m;
        cin >> n >> x >> m;
        ll sum = 0;
        // cout << x % m << " ";
        ll cnt = 0;
        rep(i, k) {
            sum += d[i] % m;
            if (d[i] % m == 0) cnt++;
            // cout << d[i] % m << " ";
        }
        // cout << endl;
        sum *= (n - 1) / (ll)k;
        cnt *= (n - 1) / (ll)k;
        sum += x % m;
        rep(i, (n - 1) % k) {
            sum += d[i] % m;
            if (d[i] % m == 0) cnt++;
        }
        cout << n - 1 - cnt - sum / m << endl;
    }
}
