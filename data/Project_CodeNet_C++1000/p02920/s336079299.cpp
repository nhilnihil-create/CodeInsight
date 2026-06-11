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
    bool solve(vector<int>& A) {
        int N = A.size();
        int n = 0;
        while (1 << n < N) {
            ++n;
        }


        multiset<int, greater<int>> M;
        multiset<int, greater<int>> R;
        for (auto x : A) {
            R.insert(x);
        }
        M.insert(*R.begin());
        R.erase(R.begin());

        for (int i = 0; i < n; ++i) {
            if (M.size() != (1 << i)) {
                return false;
            }
            auto it = M.begin();
            vector<int> nxt;
            for (int j = 0; j < (1 << i); ++j, ++it) {
                int x = *it;
                auto it2 = R.upper_bound(x);
                if (it2 == R.end()) {
                    return false;
                }
                nxt.push_back(*it2);
                R.erase(it2);
            }
            for (auto x : nxt) {
                M.insert(x);
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        cin >> A[i];
    }
    Solution sol;
    if (sol.solve(A)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}