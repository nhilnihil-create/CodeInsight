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
    long long solve(vector<int>& P) {
        int n = P.size();
        int h = 0;
        while (1 << (h + 1) <= n) {
            ++h;
        }

        auto build = [&](vector<int>& P) {
            int n = P.size();
            vector<vector<int>> maxs(n, vector<int>(1 + h, 0));
            for (int i = 0; i < n; ++i) {
                maxs[i][0] = i + 1 < n ? P[i + 1] : 0;
            }

            for (int i = n - 1; i >= 0; --i) {
                for (int j = 1; j <= h; ++j) {
                    int k = min(n - 1, i + (1 << (j - 1)));
                    maxs[i][j] = max(maxs[i][j - 1], maxs[k][j - 1]);
                    // cout << i << "," << j << " " << maxs[i][j] << endl;
                }
            }
            // cout << endl;
            return maxs;
        };

        // vector<vector<int>> maxL;
        // vector<vector<int>> maxR;
        reverse(P.begin(), P.end());
        auto maxL = build(P);
        reverse(P.begin(), P.end());
        auto maxR = build(P);

        auto find = [&](vector<vector<int>>& maxs, int beg, int x) {
            int res = beg;
            for (int i = h; i >= 0; --i) {
                int p = res + (1 << i);
                if (p >= n) {
                    continue;
                }
                // cout << res << ", " << i << " : " << maxs[res][i] << " " << x << endl;
                if (maxs[res][i] <= x) {
                    res += (1 << i) ;
                }
            }
            return res + 1;
        };


        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int x = P[i];
            int l = find(maxL, n - 1 - i, x);
            int ll = find(maxL, l, x);
            // cout << "RRR " << endl;
            int r = find(maxR, i, x);
            int rr = find(maxR, r, x);

            // cout << l << " " << ll << endl;
            l = n - 1 - l;
            ll = n - 1 - ll;
            ll = max(-1, ll);
            rr = min(n, rr);
            // cout << i << ": " << x << " ::: " << ll << " " << l << " " << r << " " << rr << endl;

            if (l >= 0 || r < n) {
                int l1 = l - ll;
                int l2 = i - l;
                int r1 = rr - r;
                int r2 = r - i;
                long long cnt = l1 * r2 + l2 * r1;
                // cout << x << " " << cnt << " " << cnt * x << endl;
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
    vector<int> P(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
    }

    Solution sol;
    cout << sol.solve(P) << "\n";
    return 0;
}