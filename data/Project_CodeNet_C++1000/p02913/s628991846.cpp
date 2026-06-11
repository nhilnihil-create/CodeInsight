#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<int>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main() {
    int N;
    string S;
    cin >> N >> S;
    vvl dp(N+1, vl(N+1, 0));
    per(i,N) per(j,N) {
        if (S[i] == S[j]) dp[i][j] = dp[i+1][j+1] + 1;
    }
    int ans = 0;
    rep(i,N) rep(j,N) {
        dp[i][j] = min(dp[i][j], abs(i - j));
        ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
    return 0;
}
