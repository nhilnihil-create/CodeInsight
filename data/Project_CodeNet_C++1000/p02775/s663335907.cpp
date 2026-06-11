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
    int solve(string& s) {
        int n = s.length();
        const int INF = 1 << 24;
        vector<int> dp(2, INF);
        dp[0] = 0;
        vector<int> ndp(2, INF);

        for (int i = n - 1; i >= 0; --i) {
            fill(ndp.begin(), ndp.end(), INF);

            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    for (int d = 0; d < 10; ++d) {
                        int cnt = dp[k] + d + j - k;
                        int rem = d + j * 10 - k;
                        rem -= s[i] - '0';
                        // cout << i << " " << d << " " << k << " " << rem << " " << j << " " << cnt + rem << endl;
                        if (rem >= 0 && rem < 10) {
                            ndp[j] = min(ndp[j], cnt + rem);
                            // cout << "ndp " << j << " " << ndp[j] << endl;

                        }
                    }
                }
            }
            swap(ndp, dp);
            // cout << i << " " << dp[0] << " " << dp[1] << endl;
        }
        // cout << dp[0] << " " << dp[1] << endl;
        int res = min(dp[0], dp[1]);
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    Solution sol;
    cout << sol.solve(s) << "\n";

    return 0;
}