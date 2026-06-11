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

        const long long MOD = 1e9 + 7;

        int m = 1;
        int M = 1 << m;
        vector<long long> dp(M, 0);
        dp[0] = 1;
        vector<long long> ndp(dp);
        for (int i = 0; i < n; ++i) {
            fill(ndp.begin(), ndp.end(), 0);
            int d = s[i] - '0';
            for (int j = 0; j < M; ++j) {
                int la = 0, ra = 1;
                int lb = 0, rb = 1;
                int mx = 1;
                if ((j & 1) == 0) {
                    mx = d;
                }

                for (int a = la; a <= ra; ++a) {
                    for (int b = lb; b <= rb; ++b) {
                        if (a == 1 && b == 1) {
                            continue;
                        }
                        if ((a ^ b) > mx) {
                            continue;
                        }
                        int nj = j;
                        if ((a ^ b) < d) {
                            nj |= 1;
                        }
                        // cout << a << " " << b << " " << j << endl;
                       
                        (ndp[nj] += dp[j]) %= MOD;
                    }
                }
            }
            // for (int j = 0; j < M; ++j) {
            //     cout << j << " : " << ndp[j] << endl;
            // }
            swap(ndp, dp);
        }
        long long res = 0;
        for (auto x : dp) {
            res += x;
        }
        res %= MOD;
        return res;
    }

};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    Solution sol;
    cout << sol.solve(S) << "\n";

    return 0;
}