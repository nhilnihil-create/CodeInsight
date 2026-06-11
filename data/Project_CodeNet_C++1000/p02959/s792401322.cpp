#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define DEBUG
#ifdef DEBUG
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) {
            os << ',';
        }
        os << v[i];
    }
    os << '}';
    return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &... args) {
    cerr << " " << x;
    debugg(args...);
}
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debugg(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __Setup;

using ll = long long;
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    for(int i = 0; i < n + 1; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll ans = accumulate(ALL(a), 0LL);
    for(int i = 0; i < n; i++) {
        int mn = min(a[i], b[i]);
        a[i] -= mn;
        b[i] -= mn;
        mn = min(a[i + 1], b[i]);
        a[i + 1] -= mn;
        b[i] -= mn;
    }
    ans -= accumulate(ALL(a), 0LL);
    cout << ans << endl;
}