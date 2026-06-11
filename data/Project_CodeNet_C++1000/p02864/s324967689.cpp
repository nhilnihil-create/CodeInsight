// 解答不能.
// CharlotteL氏.
// https://atcoder.jp/contests/abc145/submissions/8490302
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i <= b; i++)

int main(){
    LL inf = 1e18;
    int n;
    LL k;
    scanf("%d %lld", &n, &k);
    vector<LL> h(n + 2);
    repx(i, 1, n) scanf("%lld", &h[i]);
    vector<vector<LL>> dp(n + 2, vector<LL>(k + 1, inf));
    dp[0][0] = 0;
    repx(i, 1, n + 1){
        rep(j, i){
            int c = i - j - 1;
            LL d = max(h[i] - h[j], 0LL);
            rep(l, k - c + 1) dp[i][l + c] = min(dp[i][l + c], dp[j][l] + d);
        }
    }
    printf("%lld\n", *min_element(dp.back().begin(), dp.back().end()));
    return 0;
}