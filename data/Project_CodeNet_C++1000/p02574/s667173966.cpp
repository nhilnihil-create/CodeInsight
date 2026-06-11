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

#ifdef DEBUG
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
#else
template <class T, class... Args>
void debug(const T &x, const Args &... args) {}
template <class T> void debugVector(const vector<T> &v) {}
#endif

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

vector<int> sieve(int n) {
    vector<int> res(n);
    iota(ALL(res), 0);
    for(int i = 2; i * i < n; i++) {
        if(res[i] < i) {
            continue;
        }
        for(int j = i * i; j < n; j += i) {
            if(res[j] == j) {
                res[j] = i;
            }
        }
    }
    return res;
}

vector<int> factor(int n, const vector<int> &min_factor) {
    vector<int> res;
    while(n > 1) {
        res.emplace_back(min_factor[n]);
        n /= min_factor[n];
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<ll> se;
    bool ok = true;

    static vector<int> min_factor = sieve(1000100);
    static vector<bool> used(1000100, false);
    for(int i = 0; i < n; i++) {
        auto v = factor(a[i], min_factor);
        sort(ALL(v));
        v.erase(unique(ALL(v)), v.end());
        for(auto j : v) {
            if(used[j]) {
                ok = false;
            }
            used[j] = true;
        }
    }

    if(ok) {
        cout << "pairwise coprime\n";
        return 0;
    }
    ll g = 0;
    for(int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
    }
    if(g == 1) {
        cout << "setwise coprime\n";
    } else {
        cout << "not coprime\n";
    }
}