#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    constexpr int mod = 1000000007;
    
    string L;
    cin >> L;
    
    vector<vector<long long>> dp(L.size() + 1, vector<long long>(2, 0));
    dp[0][0] = 1;
    rep(i, L.size()) rep(j, 2) {
        for (int x = 0; x <= (j ? 1 : L[i] - '0'); ++x) {
            if (x == 0) dp[i + 1][j || x < L[i] - '0'] += dp[i][j];
            else dp[i + 1][j || x < L[i] - '0'] += 2 * dp[i][j];
            dp[i][j] %= mod;
        }
    }
    cout << (dp[L.size()][0] + dp[L.size()][1]) % mod << endl;
    return 0;
}
