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


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<int> cnts(n, 0);
    vector<int> cnts2(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] < A[j]) {
                ++cnts[i];
            }
        }
        cnts2[i] = cnts[i];
        for (int j = i + 1; j < n; ++j) {
            if (A[i] < A[j]) {
                ++cnts2[i];
            }
        }
        // cout << i << " " << cnts[i] << " " << cnts2[i] << endl;
    }

    long long MOD = 1000000007LL;
    long long inv2 = (MOD + 1) / 2;
    auto calc = [&](long long c1, long long c2, long long K) -> long long  {
        long long res = (K - 1) * K % MOD * inv2 % MOD;
        (res *= c2) %= MOD;
        (res += c1 * K % MOD) %= MOD;
        return res;
    };

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += calc(cnts[i], cnts2[i], k);
        res %= MOD;
    }

    cout << res << '\n';

    return 0;
}