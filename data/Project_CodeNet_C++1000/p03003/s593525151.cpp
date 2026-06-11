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

class Solution {
public:
    int solve(vector<int>& A, vector<int>& B) {
        const long long MOD = 1e9 + 7;
        int n = A.size();
        int m = B.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i] == B[j]) {
                    (dp[i + 1][j + 1] += (dp[i][j] + 1)) %= MOD;
                }
                (dp[i + 1][j + 1] += dp[i + 1][j] + dp[i][j + 1] + MOD - dp[i][j]) %= MOD;
            }
        }

        long long res = dp[n][m];
        res += 1;
        res %= MOD;
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    Solution sol;
    cout << sol.solve(A, B) << "\n";

    return 0;
}