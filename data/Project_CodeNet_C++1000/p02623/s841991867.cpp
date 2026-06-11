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

void solve() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m), psa(n+1), psb(m+1);
    for (long long &x : a)
        cin >> x;
    for (long long &x : b)
        cin >> x;
    partial_sum(a.begin(), a.end(), psa.begin()+1);
    partial_sum(b.begin(), b.end(), psb.begin()+1);

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        if (psa[i] > k) break;
        int pp = upper_bound(psb.begin(), psb.end(), k-psa[i]) - psb.begin();
//        cerr << i << ' ' << pp-1 << '\n';
        ans = max(ans, i+pp-1);
    }
    cout << ans << '\n';
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