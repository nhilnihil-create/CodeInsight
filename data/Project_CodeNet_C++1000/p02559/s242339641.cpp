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
#define MAXN 500005
//#define MOD 998244353LL
#define MOD 1000000007LL

long long T[MAXN];

void add(int x, int v) {
    for (++x; x < MAXN; x += x&-x) {
        T[x] += v;
    }
}

long long sum(int x) {
    long long ans = 0;
    for (++x; x; x -= x&-x) {
        ans += T[x];
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        add(i, x);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            add(p, x);
        }
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << sum(r-1) - sum(l-1) << '\n';
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