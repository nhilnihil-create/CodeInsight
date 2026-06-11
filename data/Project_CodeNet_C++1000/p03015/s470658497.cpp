#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

const llong mod = (llong)(1e9) + 7;
string l;
llong dp[2][2][2][100005];

llong dfs(int smaller, int n, int m, int i) {
    if (dp[smaller][n][m][i] != -1) return dp[smaller][n][m][i];
    if (l.size() == i) return 1;

    if (l[i + 1] == '0' && smaller == 0) {
        return dp[smaller][n][m][i] = dfs(smaller, 0, 0, i + 1) % mod;
    }
    else {
        return dp[smaller][n][m][i] = (dfs(smaller, 0, 1, i + 1) + dfs(smaller, 1, 0, i + 1) +
                                       dfs(1, 0, 0, i + 1)) % mod;
    }
}

llong pow_mod(llong n, llong m) {
    llong res = 1;

    while (m) {
        if (m & 1) {
            res *= n;
            res %= mod;
        }

        n *= n;
        n %= mod;
        m >>= 1;
    }

    return res;
}

int main() {
    cin >> l;

    for (int i = 0; i < 100005; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[j][k][0][i] = -1;
                dp[j][k][1][i] = -1;
            }
        }
    }

    dfs(1, 0, 0, 0);
    dfs(0, 0, 1, 0);
    dfs(0, 1, 0, 0);

    cout << (dp[1][0][0][0] + dp[0][0][1][0] + dp[0][1][0][0]) * pow_mod(3, mod - 2) % mod << endl;

    return 0;
}
