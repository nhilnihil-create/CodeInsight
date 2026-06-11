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
    long long solve(vector<int>& A, int K) {
        int n = A.size();
        
        map<int,vector<int>> M;
        M[0].push_back(-1);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i] - 1;
            M[sum % K].push_back(i);
        }

        long long res = 0;
        for (auto& P : M) {
            auto& V = P.second;
            int n = V.size();
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && V[j] - V[i] < K) {
                    ++j;
                }
                res += max(0, j - i - 1);
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
    int k;
    cin >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    Solution sol;

    cout << sol.solve(A, k) << "\n";

    return 0;
}