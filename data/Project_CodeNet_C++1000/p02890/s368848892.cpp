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
    int n;
    cin >> n;
    map<int, ll> cnt;
    rep(i, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    vector<ll> vec;
    for (auto p : cnt) {
        vec.push_back(p.second);
    }
    sort(all(vec));
    vector<ll> sum(sz(vec) + 1);
    rep(i, sz(vec)) sum[i + 1] = sum[i] + vec[i];

    for (ll k = 1; k <= n; k++) {
        ll ok = 0, ng = INF;
        while (ng - ok > 1) {
            ll mid = (ok + ng) / 2;
            ll idx = (ll)(lower_bound(all(vec), mid) - vec.begin());
            if (sum[idx] + mid * (ll)(sz(vec) - idx) >= mid * k) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok << endl;
    }
}
