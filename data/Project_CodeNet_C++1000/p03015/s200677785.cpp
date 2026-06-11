#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int mod = 1e9 + 7;
int dp[100005][2];

int main() {
    string L; cin >> L;
    int ss = L.size();

    dp[0][0] = 1;
    rep(i, ss){
        //a+b[i] = 0
        if(L[i] == '0'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
        } else {
            dp[i+1][1] = (dp[i][0] + dp[i][1]) % mod;
        }
        //a+b[i] = 1
        if(L[i] == '0'){
            (dp[i+1][1] += (dp[i][1] * 2) % mod) %= mod;
        } else {
            (dp[i+1][0] += (dp[i][0] * 2) % mod) %= mod;
            (dp[i+1][1] += (dp[i][1] * 2) % mod) %= mod;
        }
    }

    int ans = dp[ss][0] + dp[ss][1];
    ans %= mod;

    cout << ans << endl;

    return 0;
}