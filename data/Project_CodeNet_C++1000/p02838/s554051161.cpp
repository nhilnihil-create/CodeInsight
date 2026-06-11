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

const int N = 3e5 + 7, MOD = 1e9 + 7;

int calc[60], a[N], deg[60] = { 1 };

void solve() {
    loop1(i, 59)
        deg[i] = deg[i - 1] * 2 % MOD;
    int n; cin >> n;
    loop(i, n) {
        cin >> a[i];
        loop(bit, 60)
            calc[bit] += bool(a[i] & (1ll << bit));
    }
    int ans = 0;
    loop(i, n)
        loop(bit, 60) {
            calc[bit] -= bool(a[i] & (1ll << bit));
            ans = (ans + (a[i] & (1ll << bit) ? n - i - 1 - calc[bit] : calc[bit]) * deg[bit]) % MOD;
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
