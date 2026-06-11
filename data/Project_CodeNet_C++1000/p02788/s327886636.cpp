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
    long long solve(vector<int>& X, vector<int>& H, int a, int d) {
        int n = X.size();
        vector<int> SX(X);
        sort(SX.begin(), SX.end());
        
        auto index = [&](int x) {
            return lower_bound(SX.begin(), SX.end(), x ) - SX.begin();
        };

        vector<int> R(n, -1);
        iota(R.begin(), R.end(), 0);

        for (int i = 0; i < n; ++i) {
            long long r = X[i] + 0LL + d * 2LL;
            r = min(r, (long long) SX.back() + 1);
            X[i] = index(X[i]);
            R[i] = index(r);
            // if (R[i] == n || SX[R[i]] > r) {
            //     --R[i];
            // }
            if (R[i] < n && SX[R[i]] == r) {
                ++R[i];
            }
            H[i] = (H[i] + a - 1) / a;
        }

        {
            auto TX = X;
            auto TR = R;
            auto TH = H;
            for (int i = 0; i < n; ++i) {
                int x = X[i];
                R[x] = TR[i];
                H[x] = TH[i];
            }
        }

        vector<long long> cnts(n + 1 + 1, 0);

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            cnts[i + 1] += cnts[i];
            auto h = H[i] - cnts[i + 1];
            // cout << H[i] << " " << h << " " << cnts[i + 1] << " " << R[i] << endl;
            if (h > 0) {
                res += h;
                int r = R[i];
                cnts[i + 1] += h;
                cnts[r + 1] -= h;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d, a;
    cin >> n >> d >> a;
    vector<int> X(n);
    vector<int> H(n);

    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> H[i];
    }

    Solution sol;

    cout << sol.solve(X, H, a, d) << "\n";

    return 0;
}