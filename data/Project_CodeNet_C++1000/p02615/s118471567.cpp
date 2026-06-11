#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <unordered_map>
#include <numeric>
#include <random>
#include <memory>
#include <chrono>
#include <functional>
#include <unordered_set>
#include <cstring>
#include <cassert>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif

//#define int ll
#pragma GCC optimize("Ofast")


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
#define sz(x) int((x).size())

#ifdef ONLINE_JUDGE
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#else
mt19937 rng(1000 - 7);
#endif

const int N = 2e3 + 10;
const int inf = INT_MAX / 2;
const ll INF = LLONG_MAX / 3;
//const int MOD = 998244353;
const int MOD = 1e9 + 7;
const ld eps = 1e-6;
const pii dir[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };



signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(9);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    sort(a.rbegin(), a.rend());
    ll ans = 0;

    ans += a.front();
    if (n > 2) {
        ans += a[1];
    }
    
    vector <int> b = { a[0], a[1], a[2] }, c;
    int j = 0;
    for (int i = 3; i < n; i++) {
        if (j == sz(b)) {
            vector <int> v;
            for (int k = 0; k < sz(b); k++) {
                v.push_back(b[k]);
                v.push_back(c[k]);
            }
            b = v;
            c.clear();
            j = 0;
        }
        ans += min(b[j], b[(j + 1) % sz(b)]);
        debug(j, b, min(b[j], b[(j + 1) % sz(b)]));
        j++;
        c.push_back(a[i]);
    }

    cout << ans << "\n";

    return 0;
}
