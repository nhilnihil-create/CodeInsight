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
    long long solve(vector<long long>& A) {
        int n = A.size();
        int h = 0;
        {
            long long mx = *max_element(A.begin(), A.end());
            while ((1LL << (h + 1)) <= mx) {
                ++h;
            }
        }


        long long X = 0;
        for (auto x : A) {
            X ^= x;
        }

        vector<long long> LB;
        auto add = [&](long long x) {
            for (auto y : LB) {
                x = min(x, x ^ y);
            }
            if (x == 0) {
                return;
            }
            LB.push_back(x);
            for (int i = (int) LB.size() - 1; i > 0; --i) {
                if (LB[i] > LB[i - 1]) {
                    swap(LB[i], LB[i - 1]);
                }
            }
        };

        auto getMax = [&]() {
            long long res = 0;
            for (auto x : LB) {
                res = max(res, res ^ x);
            }
            return res;
        };

        for (auto x : A) {
            add(x & (~X));
        }

        long long res = (getMax() << 1) + X;
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    Solution sol;
    cout << sol.solve(A) << "\n";

    return 0;
}