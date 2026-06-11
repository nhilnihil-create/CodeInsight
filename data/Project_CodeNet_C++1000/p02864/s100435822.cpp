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
    long long solve (vector<int>& H, int K) {
        int n = H.size();
        vector<int> X(H);
        X.push_back(0);
        sort(X.begin(), X.end());
        X.resize(unique(X.begin(), X.end()) - X.begin());
        auto index = [&](int x) {
            return lower_bound(X.begin(), X.end(), x) - X.begin();
        };
        vector<int> A(n, 0);
        for (int i = 0; i < n; ++i) {
            A[i] = index(H[i]);
        }
        int N = X.size();

        const long long INF = 1LL << 50;
        vector<vector<long long>> dp(K + 1, vector<long long>(N, INF));
        vector<vector<long long>> ndp(dp);
        dp[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            for (auto& V : ndp) {
                fill(V.begin(), V.end(), INF);
            }
            for (int j = 0; j <= K; ++j) {
                long long mn = INF;
                for (int k = 0; k < N; ++k) {
                    // if (dp[j][k] >= INF) {
                    //     continue;
                    // }
                    int nj = j;
                    if (k != A[i]) {
                        ++nj;
                    }
                    mn = min(mn, dp[j][k] - X[k]);
                    
                    if (nj <= K) {
                        ndp[nj][k] = min(ndp[nj][k], mn + X[k]);
                    }
                }
            }

            for (int j = 0; j <= K; ++j) {
                long long mn = INF;
                for (int k = N - 1; k >= 0; --k) {
                    // if (dp[j][k] >= INF) {
                    //     continue;
                    // }
                    int nj = j;
                    if (A[i] != k) {
                        ++nj;
                    }
                    mn = min(mn, dp[j][k]);
                    if (nj <= K) {
                        ndp[nj][k] = min(ndp[nj][k], mn);
                    }
                }
            }
            swap(ndp, dp);
            // cout << endl  << endl;
            // for (int i = 0; i <= K; ++i) {
            //     for (int j = 0; j < N; ++j) {
            //         if (dp[i][j] < INF) {
            //             cout << i << "," << j << " : " << dp[i][j] << endl;
            //         }
            //     }
            // }
        }

        long long res = INF;
        for (int i = 0; i <= K; ++i) {
            for (int j = 0; j < N; ++j) {
                res = min(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    Solution sol;
    cout << sol.solve(A, k) << "\n";

    return 0;
}