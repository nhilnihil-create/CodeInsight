#define _CRT_SECURE_NO_WARNINGS

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
#define mkt make_tuple
#define no {cout << -1; return;}

const int N = 2007;

int up[N][N], dwn[N][N], lef[N][N], rig[N][N];
bool f[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    loop1(i, n) {
        loop1(j, m) {
            char c; cin >> c;
            f[i][j] = c == '#';
            lef[i][j] = (c == '#' ? 0 : lef[i][j - 1] + 1);
            up[i][j] = (c == '#' ? 0 : up[i - 1][j] + 1);
        }
    }
    int ans = 0;
    for (int i = n; i > 0; --i) {
        for (int j = m; j > 0; --j) {
            rig[i][j] = (f[i][j] ? 0 : rig[i][j + 1] + 1);
            dwn[i][j] = (f[i][j] ? 0 : dwn[i + 1][j] + 1);
            ans = max(ans, rig[i][j] + lef[i][j] + up[i][j] + dwn[i][j] - 3);
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}