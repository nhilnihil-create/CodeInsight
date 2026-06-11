#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize ("trapv")
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 300005
//#define MOD 998244353LL
#define MOD 1000000007LL

int p[MAXN];
int n, q;

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

void join(int x, int y) {
    x = get(x), y = get(y);
    p[x] = y;
}

void solve() {
    cin >> n >> q;
    iota(p+1, p+1+n, 1);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            join(u, v);
        }
        if (t == 1) {
            cout << (get(u) == get(v)) << '\n';
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}