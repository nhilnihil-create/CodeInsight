//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")
           
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
           
//#define int long long
  
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

template<typename T>
using kawaii_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
  
void FAST_IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
    #ifndef _offline
    //freopen("mincost.in", "r", stdin);
    //freopen("mincost.out", "w", stdout);
    #endif
}

const int MAXN = 1e6 + 100;
int fact[MAXN];

int c(int n, int k) {
    int res = fact[n] - fact[k] - fact[n - k];
    return (res ^ 1);
}

signed main() {
    FAST_IO();
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] + __builtin_ctz(i);
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        s[i]--;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && c(n - 1, i) == 1) {
            res ^= 1;
        }
    }
    if (res == 1) {
        cout << 1 << '\n';
        return 0;
    }
    bool f = false;
    for (int i = 0; i < n; ++i) {
        f |= (s[i] == '1');
    }
    if (f) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2' && c(n - 1, i) == 1) {
            res ^= 2;
        }
    }
    cout << res << '\n';
}  