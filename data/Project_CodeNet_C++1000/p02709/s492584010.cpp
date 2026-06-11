#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;



void run_case() {
    int n; cin >> n;
    vector<pll> a;
    for(int i = 1; i <= n; ++i) {
        LL t; cin >> t;
        a.emplace_back(t, 1LL*i);
    }
    sort(a.begin(), a.end(), [&](pll a, pll b) {
        return a.first > b.first;
    });
    vector<vector<LL>> dp(n+2, vector<LL>(n+2));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) {   // len = r - l + 1, len = n - i
            int l = j+1, r = n - i + l - 1;
            if(r+1<=n) dp[l][r] = max(dp[l][r], dp[l][r+1]+abs(r+1-a[i-1].second)*a[i-1].first);
            if(l-1>=1) dp[l][r] = max(dp[l][r], dp[l-1][r]+abs(l-1-a[i-1].second)*a[i-1].first);
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; ++i) ans = max(ans, dp[i][i-1]);
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}