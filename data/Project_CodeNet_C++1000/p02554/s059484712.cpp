#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    cin >> n;

    vector<long long> dp(4, 0);
    dp[0] = 1;
    auto ndp = dp;

    const long long MOD = 1000000007;
    for (int i = 0; i < n; ++i) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int j = 0; j < 4; ++j) {
            if (dp[j] == 0) {
                continue;
            }
            (ndp[j] += dp[j] * 8 % MOD) %= MOD;
            {
                int nj = j | 1;
                (ndp[nj] += dp[j]) %= MOD;
            }
            {
                int nj = j | 2;
                (ndp[nj] += dp[j]) %= MOD;
            }
        }
        swap(ndp, dp);
    }

    cout << dp[3] << '\n';

    return 0;
}