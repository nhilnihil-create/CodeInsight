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
    cout << fixed << setprecision(12);

    int S;
    cin >> S;

    const long long MOD = 1000000007;

    vector<long long> dp(S + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < S; ++i) {
        for (int j = S - i; j >= 3; --j) {
            (dp[j + i] += dp[i]) %= MOD;
        }
    }

    cout << dp[S] << '\n';
    return 0;
}