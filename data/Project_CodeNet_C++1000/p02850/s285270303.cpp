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

const int N = 1e5 + 7;

int ans[N], num;
vector <pi> g[N];

void dfs(int v, int p, int lstc) {
    int cnt = 1;
    for (pi u : g[v])
        if (u.F != p) {
            if (cnt == lstc)
                ++cnt;
            num = max(num, cnt);
            ans[u.S] = cnt++;
            dfs(u.F, v, ans[u.S]);
        }
}

void solve() {
    int n; cin >> n;
    loop(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    dfs(1, 1, 0);
    cout << num << "\n";
    loop(i, n - 1)
        cout << ans[i] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
