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
    vector<pair<int,int>> solve(int n, int K) {
        int N = (n - 1) * (n - 2) / 2;
        if (K > N) {
            return {};
        }


        vector<pair<int,int>> res;
        for (int i = 1; i < n; ++i) {
            res.emplace_back(0, i);
        }
        for (int i = 1; i < n && K < N; ++i) {
            for (int j = i + 1; j < n && K < N; ++j) {
                res.emplace_back(i, j);
                --N;
            }
        }
        return res;

    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int k;
    cin >> n >> k;

    Solution sol;
    auto res = sol.solve(n, k);
    if (res.empty()) {
        cout << -1 << "\n";
    } else {
        cout << res.size() << "\n";
        for (auto& r : res) {
            cout << r.first + 1 << " " << r.second + 1 << "\n";
        }
    }
    return 0;
}