#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;
const int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int s;
    cin >> s;
    ll dp[s];
    dp[0]=1;
    dp[1]=0;
    dp[2]=0;
    for (int i=3; i<=s; ++i) {
        dp[i] = dp[i-1] + dp[i-3];
        dp[i] %= MOD;
    }
    cout << dp[s] << endl;
    return 0;
}