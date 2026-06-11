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
    vector<long long> solve(int n, int k) {
        const long long MOD = 1e9 + 7;
        const int N = n + 123;
        vector<vector<long long>> C(N + 1, vector<long long>(N + 1, 0));

        for (int i = 0; i <= N; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                (C[i][j] = C[i - 1][j - 1] + C[i - 1][j]) %= MOD;
            }
        }

        auto calc = [&](int n, int m, int k) {
            long long res = 1;
            (res *= C[n - 1][k - 1]) %= MOD;
            (res *= C[m + 1][k]) %= MOD;
            return res;
        };

        vector<long long> res(k, 0);

        for (int i = 0; i < k; ++i) {
            res[i] = calc(k, n - k, i + 1);
        }

        return res;
    }

};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    Solution sol;
    auto res = sol.solve(n, k);
    for (int i = 0; i < k; ++i) {
        cout << res[i] << "\n";
    }
    return 0;
}