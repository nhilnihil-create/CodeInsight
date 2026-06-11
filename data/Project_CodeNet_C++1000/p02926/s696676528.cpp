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
    long double solve(vector<int>& X, vector<int>& Y) {
        int n = X.size();
        vector<int> A(n, 0);
        iota(A.begin(), A.end(), 0);
        
        auto cmp = [&](int l, int r) {
            int x1 = X[l], y1 = Y[l];
            int x2 = X[r], y2 = Y[r];
            double L = -1234;
            double R = -1234;
            if (x1 != 0 || y1 != 0) {
                L = atan2(y1, x1);
            } 
            if (x2 != 0 || y2 != 0) {
                R = atan2(y2, x2);
            }
            return L < R;
        };
        sort(A.begin(), A.end(), cmp);

        A.resize(n * 2);
        for (int i = 0; i < n; ++i) {
            A[i + n] = A[i];
        }

        long long res = 0;
        for (int l = 0; l < n; ++l) {
            long long x = 0;
            long long y = 0;
            for (int r = l; r - l + 1 <= n; ++r) {
                int idx = A[r];
                x += X[idx];
                y += Y[idx];
                res = max(res, x * x + y * y);
            }
        }
        return sqrt(res);
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(16);

    int n;
    cin >> n;
    vector<int> X;
    vector<int> Y;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    Solution sol;

    cout << sol.solve(X, Y) << "\n";

    return 0;
}