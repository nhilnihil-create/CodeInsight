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
#define no {cout << "NO\n"; return;}
#define yes {cout << "YES\n"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

const int N = 60;

vector <pi> g[N];
int path[N];

bool dfs(int v, int p, int fin, int num) {
    if (v == fin)
        return true;
    for (pi pa : g[v])
        if (pa.F != p && dfs(pa.F, v, fin, num)) {
            path[num] = path[num] ^ (1ll << pa.S); return true;
        }
    return false;
}

void solve() {
    string s, t, u;
    int n, m;
    cin >> s >> t >> n >> m >> u;
    cout << n - (s == u) << " " << m - (t == u);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}