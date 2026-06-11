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
    long long solve(vector<int>& A) {
        int n = A.size();

        auto build = [&](vector<int>& A) {
            int n = A.size();
            int h = 0;
            while (1 << (h + 1) <= n) {
                ++h;
            }

            vector<vector<int>> res(n, vector<int>(h + 1, 0));
            for (int i = 0; i < n; ++i) {
                res[i][0] = A[i];
            }
            for (int j = 1; j <= h; ++j) {
                for (int i = 0; i < n; ++i) {
                    int k = i + (1 << (j - 1));
                    res[i][j] = res[i][j - 1];
                    if (k < n) {
                        res[i][j] = max(res[i][j], res[k][j - 1]);
                    }
                }
            }
            return res;
        };

        auto find = [&](vector<vector<int>>& maxs, int beg, int x) {
            int h = maxs[0].size();
            int n = maxs.size();
            int res = beg;
            for (int i = h - 1; i >= 0 && res < n; --i) {
                if (res + (1 << i) > n) {
                    continue;
                }
                if (maxs[res][i] <= x) {
                    res += 1 << i;
                }
            }
            return res;
        };

        reverse(A.begin(), A.end());
        auto maxsL = build(A);
        reverse(A.begin(), A.end());
        auto maxsR = build(A);

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int x = A[i];

            int l = find(maxsL, n - 1 - i, x);
            int ll = find(maxsL, l + 1, x);

            l = n - 1 - l;
            ll = n - 1 - ll;
            ll = max(-1, ll);

            int r = find(maxsR, i, x);
            int rr = find(maxsR, r + 1, x);
            rr = min(n, rr);

            if (l >= 0 || r < n) {
                long long cnt = (l - ll) * 1LL * (r - i) + (i - l) * 1LL * (rr - r);
                res += cnt * x;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    Solution sol;
    cout << sol.solve(A) << "\n";

    return 0;
}