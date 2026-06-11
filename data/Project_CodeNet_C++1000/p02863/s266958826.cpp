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
    int solve(vector<int>& A, vector<int>& B, int T) {
        int n = A.size();

        vector<pair<int,int>> D;
        for (int i = 0; i < n; ++i) {
            D.emplace_back(A[i], B[i]);
        }
        auto cmp = [&](const pair<int,int>& l, const pair<int,int>& r) {
            if (l.first == r.first) {
                return l.second > r.second;
            }
            return l.first < r.first;
        };
        sort(D.begin(), D.end(), cmp);

        const int INF = 1 << 28;
        vector<int> dp(T + 1, 0);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = T - 1; j >= 0; --j) {
                int nj = j + D[i].first;
                nj = min(nj, T);
                dp[nj] = max(dp[nj], dp[j] + D[i].second);
            }
        }

        int res = *max_element(dp.begin(), dp.end());
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        cin >> B[i];
    }

    Solution sol;
    cout << sol.solve(A, B, t) << "\n";

    return 0;
}