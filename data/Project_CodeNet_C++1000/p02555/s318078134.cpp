#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int dp[2100]; // dp[i] 和为 i 的方案数

int main() {
    int S;
    scanf("%d", &S);
    dp[0] = 1;
    for (int i = 3; i <= S; i++) { // sum
        for (int k = 3; k <= i; k++) { // next
            dp[i] = (dp[i] + dp[i - k]) % MOD;
        }
    }
    printf("%d\n", dp[S]);
    return 0;
}
