#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mem(a, s) memset(a, s, sizeof(a))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
typedef vector<int> vi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;
int _x[] = {0, 0, -1, 1, -1, 1, -1, 1};
int _y[] = {-1, 1, 0, 0, 1, -1, -1, 1};
void solve();
void pre();
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t = 1;
    // cin >> t;
    rep(i, 1, t) { solve(); }
    return 0;
}
const int mod = 1e9 + 7;
void pre() {}
void solve() {
    int ans = 0;
    int n;
    cin >> n;
    rep(i, 1, n - 1) { ans += (n - 1) / i; }
    cout << ans;
}