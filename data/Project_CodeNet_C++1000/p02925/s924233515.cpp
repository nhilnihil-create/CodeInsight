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
    int solve(vector<vector<int>>& A) {
        int n = A.size();
        int N = n * n;
        auto encode = [&](int x, int y) {
            if (x > y) {
                swap(x, y);
            }
            return x * n + y;
        };

        vector<vector<int>> graph(N);
        vector<int> indegrees(N, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j + 1 < n; ++j) {
                int u = encode(i, A[i][j - 1]);
                int v = encode(i, A[i][j]);
                graph[u].push_back(v);        
                indegrees[v] += 1;
            }
        }

        vector<int> ord;
        for (int i = 0; i < N; ++i) {
            if (indegrees[i] == 0) {
                ord.push_back(i);
            }
        }

        for (int i = 0; i < ord.size(); ++i) {
            int u = ord[i];
            for (auto v : graph[u]) {
                if (--indegrees[v] == 0) {
                    ord.push_back(v);
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            if (indegrees[i] != 0) {
                return -1;
            }
        }

        vector<int> dp(N, 0);
        reverse(ord.begin(), ord.end());

        for (auto u : ord) {
            int ans = 0;
            for (auto v : graph[u]) {
                ans = max(ans, dp[v]);
            }
            ans += 1;
            dp[u] = ans;
        }

        int res = *max_element(dp.begin(), dp.end());
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j + 1 < N; ++j) {
            int x;
            cin >> x;
            --x;
            A[i].push_back(x);
        }
    }
    Solution sol;
    cout << sol.solve(A) << "\n";

    return 0;
}