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

const int MOD = 1e9 + 7, N = 1e5 + 7;

int dp[N];
bool bad[N];

void solve() {
    int n, m;
    cin >> n >> m;
    int lst = 0, ans = 1;
    loop(i, m) {
        int x; cin >> x;
        bad[x] = 1;
    }
    dp[0] = 1;
    dp[1] = !bad[1];
    for (int i = 2; i <= n; ++i) {
        if (bad[i])
            continue;
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}