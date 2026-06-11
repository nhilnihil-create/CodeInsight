#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <cassert>
#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

ll dp[2005][2005];

void solve()
{
    int n;
    scanf("%d", &n);
    vector<pair<int,int> > z(n);  // val,id
    int i,j;
    for (i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        z[i] = make_pair(tmp, i);
    }
    sort(z.rbegin(), z.rend());

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (dp[i][j] < 0) continue;

            int val = z[i].first;
            int id  = z[i].second;
            dp[i + 1][j+1] = MAX(dp[i + 1][j+1], dp[i][j]+(ll)val*(id-j));
            dp[i + 1][j] = MAX(dp[i + 1][j], dp[i][j]+(ll)val*(n-1-(i-j)-id));
        }
    }

    ll ans = 0;
    for (j = 0; j <= n; j++) {
        ans=MAX(ans, dp[n][j]);
    }
    printf("%lld\n", ans);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

