#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 15, M = 1003;
int dp[1<<N];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    scanf("%d %d", &n, &m);
    memset(dp, 0x7f, sizeof dp);
    int MAX = dp[0];
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        int cost, sz;
        scanf("%d %d", &cost, &sz);
        int mask = 0;
        while (sz--) {
            int x;
            scanf("%d", &x);
            x--;
            mask |= 1 << x;
        }
        for (int j = (1 << n) - 1; j >= 0; j--) {
            dp[j|mask] = min(dp[j|mask], dp[j] + cost);
        }
    }
    if (dp[(1 << n)-1] == MAX) {
        printf("-1");
    } else {
        printf("%d", dp[(1 << n)-1]);
    }
    return 0;
}
