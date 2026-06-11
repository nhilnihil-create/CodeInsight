#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const size_t INF=1uLL<<57;

size_t num_coin(vector<size_t> c, size_t n) {
    vector<size_t> dp(n+1, INF); dp[0]=0;

    size_t m=c.size();
    for (size_t i=0; i<m; ++i)
        for (size_t j=c[i]; j<=n; ++j)
            if (dp[j] > dp[j-c[i]] + 1)
                dp[j] = dp[j-c[i]] + 1;

    return dp[n];
}

int main() {
    size_t n, m;
    scanf("%zu %zu", &n, &m);

    vector<size_t> c(m);
    for (size_t i=0; i<m; ++i)
        scanf("%zu", &c[i]);

    printf("%zu\n", num_coin(c, n));
    return 0;
}