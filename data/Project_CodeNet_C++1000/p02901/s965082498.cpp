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
#define mkt make_tuple
#define no {cout << "-1\n"; return;}

const int N = 12, M = 1007, INF = 1e18;

int dp[1 << N];
int key[M], cost[M];

void solve() {
    int n, m;
    cin >> n >> m;
    loop(i, m) {
        int k;
        cin >> cost[i] >> k;
        loop(j, k) {
            int b; cin >> b;
            key[i] ^= 1 << (b - 1);
        }
    }
    loop1(mask, (1 << n) - 1) {
        dp[mask] = INF;
        loop(i, m) {
            if ((key[i] & mask) == 0)
                continue;
            dp[mask] = min(dp[mask], dp[(mask ^ key[i]) & mask] + cost[i]);
        }
    }
    cout << (dp[(1 << n) - 1] == INF ? -1 : dp[(1 << n) - 1]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}