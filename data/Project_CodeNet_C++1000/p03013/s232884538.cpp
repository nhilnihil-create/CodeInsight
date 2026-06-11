#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> broken(n);
    rep(i,m) {
        int a;
        cin >> a;
        broken[a] = 1;
    }
    vector<int> dp(n+2);
    dp[n] = 1;
    const int mod = 1e9 + 7;
    for (int i = n-1; i >= 0; i--) {
        if (broken[i]) continue;
        dp[i] = (dp[i+1] + dp[i+2])%mod;
    }
    cout << dp[0] << endl;
    return 0;
}