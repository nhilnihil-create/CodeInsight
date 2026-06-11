#ifdef BUILT_LOCAL

#include "niklib.h"

#endif

#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
constexpr ll mod = 1000000007;

ll n, m, s[2000], t[2000];

ll rec1(ll, ll);

ll rec2(ll, ll);

ll dp[2][2000][2000][2];

ll rec1(ll a, ll b) {
    if (a < 0 || b < 0) return 0;
    if (dp[0][a][b][0] == 0) {
        dp[0][a][b][0] = 1;
        dp[0][a][b][1] = (a < 0 || b < 0 || s[a] != t[b]) ? 0 : (rec2(a - 1, b - 1) + 1) % mod;
    }
    return dp[0][a][b][1];
}

ll rec2(ll a, ll b) {
    if (a < 0 || b < 0) return 0;
    if (dp[1][a][b][0] == 0) {
        dp[1][a][b][0] = 1;
        dp[1][a][b][1] = (a < 0 || b < 0) ? 0 :
                         (rec2(a - 1, b) + rec2(a, b - 1) - rec2(a - 1, b - 1) + rec1(a, b) + mod) %
                         mod;
    }
    return dp[1][a][b][1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < 2000; i++)
        for (int j = 0; j < 2000; j++)
            dp[0][i][j][0] = dp[0][i][j][1] = dp[1][i][j][0] = dp[1][i][j][1] = 0;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    cout << (rec2(n - 1, m - 1) + 1) % mod << endl;
}