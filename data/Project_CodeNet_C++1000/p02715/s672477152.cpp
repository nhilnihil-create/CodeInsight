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
#define no {cout << "No"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if (0) cerr

const int N = 1e5 + 7, MOD = 1e9 + 7;

int calc[N];

int binpow(int x, int deg) {
    int ans = 1;
    while (deg) {
        if (deg & 1)
            ans = ans * x % MOD;
        x = x * x % MOD;
        deg >>= 1;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = k; i > 0; --i) {
        calc[i] = binpow(k / i, n);
        for (int j = 2; j * i <= k; ++j)
            calc[i] = (calc[i] - calc[j * i] + MOD) % MOD;
    }
    int ans = 0;
    loop1(i, k)
        ans = (ans + i * calc[i]) % MOD;
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
