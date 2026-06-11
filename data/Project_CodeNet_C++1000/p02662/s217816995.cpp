#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define pb push_back
#define pii pair <int, int>
#define print(x) for(auto it : x) cout << it << ' ';
#define endl "\n" // TODO: remove
#define int long long

const int N = (int)(1e6) + 322;
const int inf = (int)(2e9);
const int mod = 998244353; // check modulo

int dp[3030][3030], a[3030];

void solve() {
    int n, s; cin >> n >> s;
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        for(int j = 0; j <= s; ++j) {
            if (j - a[i] >= 0) dp[i][j] = (dp[i - 1][j - a[i]] + dp[i][j]) % mod;
            dp[i][j] = (dp[i][j] + dp[i -  1][j] * 2) % mod;
        }
    }
    cout << dp[n][s];
}

signed main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("elevator.in", "r", stdin);
//    freopen("elevator.out", "w", stdout);
//    int test; cin >> test;
//    for(int t = 1; t <= test; ++t) {
        solve();
//    }
    return 0;
}
