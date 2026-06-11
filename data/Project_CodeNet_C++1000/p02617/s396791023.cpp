#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vi2;
typedef vector<vi2> vi3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<vll> vll2;
typedef vector<vll2> vll3;
typedef vector<bool> vb;

#define el '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define repeat(n) for (int i = 0; i < n; i++)
#define umap unordered_map
#define uset unordered_set
#define vec vector
#define loop(a) for (auto &x : a)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back

template <typename T>
void debug0(const T &value) {
    cerr << value << endl;
}

template <typename T, typename... Args>
void debug0(const T &value, const Args &... args) {
    cerr << value << ' ';
    debug0(args...);
}

#ifdef LOCAL
#define debug(...) debug0(__VA_ARGS__)
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi2 adj(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll f1 = 0;
    ll ans = 0;
    repi(L, n - 1, 0) {
        ll f2 = f1 + (n - L);
        loop(adj[L]) {
            if (L < x) {
                f2 -= n - x;
            }
        }
        f1 = f2;
        debug("L", L, "f1", f1);
        ans += f1;
    }
    cout << ans << el;
}
