#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <climits>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define no {cout << -1; return;}
#define yes {cout << "Yes"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

vector <pi> a[20];

void solve() {
    int n; cin >> n;
    loop(i, n) {
        int sz; cin >> sz;
        loop(j, sz) {
            int x, y;
            cin >> x >> y;
            --x;
            a[i].pb({ x, y });
        }
    }
    int ans = 0;
    loop(mask, (1 << n)) {
        bool ok = 1;
        int sz = 0;
        loop(bit, n)
            if (mask & (1 << bit)) {
                ++sz;
                for (auto p : a[bit])
                    if (bool(mask & (1 << p.F)) != p.S)
                        ok = 0;
            }
        if (ok)
            ans = max(ans, sz);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
