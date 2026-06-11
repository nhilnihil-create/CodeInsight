#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

constexpr int kMOD = 1000000007;
constexpr uint64_t kINF = 0xFFFFFFFFFFFFFFFF;

int main() {
    uint64_t N, M;
    cin >> N >> M;

    vector<uint64_t> dp(N+4, 0);
    rep(i, M) {
        uint64_t tmp;
        cin >> tmp;
        dp[tmp] = kINF;
    }

    dp[0] = 1;
    rep(i, N) {
        if(dp[i] == kINF)
            continue;

        if(dp[i+1] != kINF) {
            dp[i+1] += dp[i];
            dp[i+1] %= kMOD;
        }

        if(dp[i+2] != kINF) {
            dp[i+2] += dp[i];
            dp[i+2] %= kMOD;
        }
    }
    cout << dp[N] << endl;
    return 0;
}

