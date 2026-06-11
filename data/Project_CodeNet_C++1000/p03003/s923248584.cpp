#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

#define NMAX 2010

const ll mod = 1000000000 + 7;
ll n, m;
ll dp[NMAX][NMAX];
ll s[NMAX], t[NMAX];

void init() {
    rep(i, 0, NMAX) {
        rep(j, 0, NMAX) dp[i][j] = 0;
    }
}

int main(){

    // input
    cin >> n >> m;
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, m) cin >> t[i];

    // init dp table
    init();

    // lcs
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % mod;
            dp[i][j] += mod;
            dp[i][j] %= mod;
        }
    }

    // debug
    /*
    rep(i, 0, n+1) rep(j, 0, m+1) {
        fprintf(stderr, "%3lld", dp[i][j]);
        fprintf(stderr, (j == n ? "\n" : " "));
    }
    */

   // print
    cout << (dp[n][m]+1) % mod << endl;

    return 0;
}