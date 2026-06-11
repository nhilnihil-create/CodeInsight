/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>

#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>

#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

// type
#include <cstdint>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

// dp[i+1][j] = 消さずに残しておいた列の数がj個で, 残っている列の最右indexがiのときの最小コスト
// dp[i+1][j] = min(dp[k+1][j-1] + max(H[i] - H[k], 0)) where k <= i-1
int dp[305][305];

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> H(N+1, 0);
    for (int i = 0; i < N; i++) cin >> H[i+1];
    fill(dp[0], dp[N+1], INF);
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= N-K; ++j) {
            for (int k = -1; k <= i-1; ++k) {
                dp[i+1][j] = min(dp[i+1][j], dp[k+1][j-1] + max(H[i+1] - H[k+1], 0LL));
            }
        }
    }

    int ret = INF;
    for (int i = 0; i <= N; ++i) ret = min(ret, dp[i][N-K]);
    cout << ret << endl;
    return 0;
}