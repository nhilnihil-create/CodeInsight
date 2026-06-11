#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define int long long
#define pb push_back
#define x first
#define ld long double
#define y second
#define mk(a,b) make_pair(a,b)
#define rr return 0
#define sqr(a) ((a)*(a))
#define all(a) a.begin(),a.end()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<class value, class cmp = less<value> >
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class value, class cmp = less_equal<value> >
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = less<key> >
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX) {
    return uniform_int_distribution<int>(l, r)(rng);
}

main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[2] = {};
    for (char c : s) {
        if (c == 'R') ++cnt[0];
        else ++cnt[1];
    }
    int ans = 1e9, cur = 0;
    for (int i = 0; i <= n; i++) {
        int red = i, white = n - i;
        int res = abs(red - cnt[0]);
        int C = max(0ll, red - cnt[0]);
        ans = min(ans, res + max(0ll, cur - C));
        if (i < n) {
            if (s[i] == 'W') ++cur;
        }
    }
    cout << ans << '\n';
}
