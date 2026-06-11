#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
template <class T>
inline void chmin(T &a, const T &b) { a = min(a, b); }
template <class T>
inline void chmax(T &a, const T &b) { a = max(a, b); }
template <class T>
inline bool kbit(const T &x, const int &k) { return ((x >> k) & 1LL); }
inline int popcount(const int &n) { return __builtin_popcount(n); }
inline ll popcountll(const ll &n) { return __builtin_popcountll(n); }
template <class T>
void zip(V<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}
void dump() {
    cerr << '\n';
}
template <class Head, class... Tail>
void dump(Head &&head, Tail &&... tail) {
    cerr << head << (sizeof...(Tail) == 0 ? " " : ", ");
    dump(std::move(tail)...);
}
template <class T>
void print(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
template <class T>
void read(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}
constexpr char sp = ' ', newl = '\n';
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll MOD = 998244353LL;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    V<int> a(n), c(3);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    for (int i = 0; i + 1 < n; i++) {
        a[i] = abs(a[i] - a[i + 1]);
        c[a[i]]++;
    }
    n--;
    if (!c[1] && c[2]) {
        for (int i = 0; i < n; i++) {
            a[i] = (a[i] > 0);
        }
    } else {
        for (int i = 0; i < n; i++) {
            a[i] = (a[i] % 2);
        }
    }
    V<ll> cnt(n + 1);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int s = i;
        while (s % 2 == 0 && s > 0) {
            s /= 2;
            cnt[i]++;
        }
        sum += cnt[i];
    }
    int res = 0;
    ll sr = 0, snr = sum;
    for (int i = 0; i < n; i++) {
        sr += cnt[i];
        snr -= cnt[n - i];
        res += (sum - sr - snr == 0) * a[i];
        res %= 2LL;
        //   dump(sum, sr, snr);
    }
    if (!c[1] && c[2]) {
        if (res == 1) {
            cout << 2 << newl;
            return 0;
        }
    }
    cout << res << newl;
}