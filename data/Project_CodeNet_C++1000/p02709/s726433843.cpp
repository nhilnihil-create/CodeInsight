#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

typedef long long LL;

const int N = 2007;
int n;
pair<int, int> a[N];

LL dp[N][N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a, a+n);
    reverse(a, a+n);

    for(int i = 0; i < n; ++i) {
        LL x, ind; tie(x, ind) = a[i];
        for(int j = 0; j <= i; ++j) {
            LL left = j, right = n-1-i+j;
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + x*abs(ind-left));
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + x*abs(ind-right));
        }
    }

    LL ans = 0;
    for(int j = 0; j <= n; ++j) {
        ans = max(ans, dp[n][j]);
    }

    cout << ans << '\n';
    
    return 0;
}
