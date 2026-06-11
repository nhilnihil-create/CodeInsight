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
    long long solve(vector<int>& A, vector<int>& F, long long K) {
        int n = A.size();
        sort(A.begin(), A.end());
        sort(F.begin(), F.end());

        auto ok = [&](long long T) {
            long long cost = 0;
            for (int i = 0, j = n - 1; i < n; ++i, --j) {
                if (T < A[i] * 1LL * F[j]) {
                    cost += max(0LL, A[i] - T / F[j]); 
                }
            }
            return cost <= K;
        };

        long long lo = 0, hi = A.back() * 1LL * F.back() + 1;

        while (lo < hi) {
            auto mi = (lo + hi) >> 1;
            if (ok(mi)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }

        return lo;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long K;
    cin >> n >> K;
    vector<int> A(n);
    vector<int> F(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> F[j];
    }

    Solution sol;
    cout << sol.solve(A, F, K) << "\n";

    return 0;
}