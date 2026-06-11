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
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

const int MAXN = 3456;
const LL MOD = 998244353;
LL dp[MAXN][MAXN];
LL pw2[MAXN];

int main() {
    pw2[0] = pw2[1] = 1;
    for (int i = 2; i < MAXN; i++)
        pw2[i] = (pw2[i - 1] * 2) % MOD;
    int N, S;
    scanf("%d %d", &N, &S);
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        int tmp;
        scanf("%d", &tmp);
        for (int j = tmp; j <= S; j++)
            dp[i][j] = dp[i - 1][j - tmp];
        for (int j = 0; j <= S; j++)
            dp[i][j] = (dp[i][j] + 2 * dp[i - 1][j]) % MOD;
    }
    printf("%lld\n", dp[N][S]);
    return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
by Benq;
*/
