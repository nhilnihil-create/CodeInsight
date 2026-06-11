#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 2345;
const int MOD = (int)1e9 + 7;
int A[MAXN], B[MAXN];
int dp[MAXN][MAXN];// 0 all, 1 use i, 2 = use j


int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= M; i++) scanf("%d", &B[i]);
    for (int i = 0; i <= N; i++) dp[i][0] = 1;
    for (int j = 0; j <= M; j++) dp[0][j] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            dp[i][j] =(dp[i][j] - dp[i - 1][j - 1] + MOD) % MOD;
            if (A[i] == B[j]) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        }
    }
    printf("%d\n", dp[N][M]);
    return 0;
}
