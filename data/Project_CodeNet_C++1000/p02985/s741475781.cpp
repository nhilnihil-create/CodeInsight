#include <cstdio>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
vector<int> G[MAXN];
int ans;
int n, k;

int mul(int x, int y) {
    return 1LL * x * y % MOD;
}



void dfs(int u, int fa) {
    int w = 2;
    if (fa == -1) {
        w--;
    }
    for (auto v : G[u]) {
        if (v == fa) {
            continue;
        }
        ans = mul(ans, k - w < 0 ? 0 : k - w);
        dfs(v, u);
        w++;
    }
    
}

int main() {
    scanf("%d%d", &n, &k);// don't forget &
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);// don't forget &
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ans = k;
    dfs(1, -1);
    printf("%d", ans);
    return 0;
}
