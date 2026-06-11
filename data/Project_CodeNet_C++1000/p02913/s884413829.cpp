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
    int solve(string& s) {
        int n = s.length();

        auto calc = [&](const string& t) {
            int n = t.length();
            vector<int> next(n + 1, -1);
            for (int i = 0, j = -1; i < n; ++i) {
                while (j != -1 && t[j] != t[i]) {
                    j = next[j];
                }
                next[i + 1] = ++j;
            }

            int res = 0;
            for (int i = 1; i <= n; ++i) {
                int j = i - next[i];
                if (j < next[i]) {
                    int l = j;
                    if (i % l == 0) {
                        int len = i / l / 2 * l;
                        res = max(res, len);
                    } else {
                        res = max(res, l);
                    }
                } else {
                    res = max(res, next[i]);
                }
            }
            return res;
        };

        int res = 0;
        for (int i = 0; i + 2 < n; ++i) {
            string t = s.substr(i);
            res = max(res, calc(t));
        }
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    Solution sol;
    cout << sol.solve(s) << "\n";

    return 0;
}