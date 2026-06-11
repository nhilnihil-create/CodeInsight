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

const int MOD = 1e9 + 7, N = 1e6 + 7;

int f[N] = { 1 }, rf[N] = { 1 };

int binpow(int x) {
    int ans = 1, d = MOD - 2;
    while (d) {
        if (d & 1)
            ans = ans * x % MOD;
        x = x * x % MOD;
        d >>= 1;
    }
    return ans;
}

int binom(int n, int k) {
    return f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

void solve() {
    loop1(i, N - 1) {
        f[i] = f[i - 1] * i % MOD;
        rf[i] = binpow(f[i]);
    }
    int x, y;
    cin >> x >> y;
    int one = x, two = 0, ans = 0;
    for (; one >= 0; ----one, ++two) {
        if (one * 2 + two == y)
            ans = (ans + binom(one + two, one)) % MOD;
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
