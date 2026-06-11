#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <bitset>

using namespace std;

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////
const int magic = 1000000007;

void add (int & a, int b) {
    a += b;
    if (a >= magic)
        a -= magic;
}

void sub (int & a, int b) {
    a -= b;
    if (a < 0)
        a += magic;
}

int mul (int a, int b) {
    return (int64)a * b % magic;
}

int FastPow(int a, int p) {
    if (!p) return 1;
    int res = FastPow(a, p >> 1);
    res = mul(res, res);
    if (p & 1) res = mul(res, a);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> dp(K + 1);
    int res = 0;
    for (int i = K; i >= 1; i--) {
        dp[i] = FastPow(K / i, N);
        for (int j = 2 * i; j <= K; j += i)
            sub(dp[i], dp[j]);
        add(res, mul(i, dp[i]));
    }

    cout << res << "\n";

    return 0;
}
