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
    void init(vector<int>& _A) {
        A = _A;
    }

    int query(int n, int x, int M) {
        int m = A.size();
        long long sum = accumulate(A.begin(), A.end(), 
                        0LL,[&](long long l, int r) { return l + r % M;});

        long long total = sum * ((n - 1) / m);
        int rem = n - 1 - (n - 1) / m * m;
        for (int i = 0; i < rem; ++i) {
            total += A[i] % M;
        }
        total += x;

        int res = n - 1 - (total / M - x / M);
        for (int i = 0; i < m; ++i) {
            if (A[i] % M == 0) {
                int cnt = (n - 1) / m + (rem > i);
                res -= cnt;
            }
        }

        return res;
    }

private:
    vector<int> A;
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, q;
    cin >> k >> q;
    vector<int> A(k);
    for (int i = 0; i < k; ++i) {
        cin >> A[i];
    }

    Solution sol;
    sol.init(A);
    while (q-- > 0) {
        int n, x, m;
        cin >> n >> x >> m;

        cout << sol.query(n, x, m) << "\n";
    }

    return 0;
}