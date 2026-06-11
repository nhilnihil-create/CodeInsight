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
        sort(A.begin(), A.end());

        long long sum = 0;
        long long res = 0;
        for (auto x : A) {
            res = gcd(res, x);
        }

        long long N = 0;
        for (auto x : A) {
            N += x;
        }

        auto check = [&](int d) {
            long long cnt = 0;
            vector<int> X;
            for (auto x : A) {
                int r = x % d;
                X.push_back(r);
                cnt += r;
            }
            sort(X.begin(), X.end(),greater<int>());
            long long n = cnt / d;
            for (int i = 0; i < n; ++i) {
                cnt -= X[i];
            }
            return cnt <= K; 
        };
        
        for (long long i = 1; i * 1LL * i <= N; ++i) {
            if (N % i == 0) {
                if (check(i)) {
                    res = max(res, i);
                }
                if (check(N / i)) {
                    res = max(res, N / i);
                }
            }
        }
        return res;
    }

private:
    long long gcd(long long a, long long b) {
        while (a != 0) {
            b %= a;
            swap(a, b);
        }
        return b;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    Solution sol;
    cout << sol.solve(A, k) << "\n";

    return 0;
}