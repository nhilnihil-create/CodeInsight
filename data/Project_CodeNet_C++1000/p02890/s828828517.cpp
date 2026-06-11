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
    vector<int> solve(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        vector<int> res(n, 0);
        vector<int> B;
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            while (i + 1 < n && A[i + 1] == A[i]) {
                ++i;
                ++cnt;
            }
            B.push_back(cnt);
        } 
        sort(B.begin(), B.end());

        int m = B.size();
        vector<int> acc(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            acc[i + 1] = acc[i] + B[i];
        }

        auto count = [&](const vector<int>& B, int K) {
            int n = B.size();
            
            int lo = 0, hi = acc[n];

            while (lo < hi) {
                auto mi = (lo + hi + 1) / 2;
                
                auto it = lower_bound(B.begin(), B.end(), mi);
                int idx = it - B.begin();
                int sum = acc[idx] + (n - idx) * mi;
                int cnt = sum / K;
                // cout << mi << " " << cnt << " " << sum << " " << hi  <<  endl;
                if (cnt >= mi) {
                    lo = mi;
                } else {
                    hi = mi - 1;
                }

            }
            return lo;
        };


        for (int i = 0; i < m; ++i) {
            res[i] = count(B, i + 1);
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
    auto res = sol.solve(A);
    for (auto r : res) {
        cout << r << "\n";
    }

    return 0;
}