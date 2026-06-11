#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

int dp[100010][13];
string S; 
int calc(int x, int d) {
    //if(x == 3) cout << x << " " << d << endl;
    if (x >= S.length()) {
        if(d == 5) return dp[x][d] = 1;
        return dp[x][d] = 0;
    }
    
    if(dp[x][d] != -1 && x != 0) return dp[x][d];
    if (S[x] != '?') {
        return dp[x][d] = calc(x + 1, (d * 10 + S[x] - '0') % 13);
    }
    int tmp = 0;
    rep(i, 10) {
        tmp = (tmp + calc(x + 1, (d*10 + i) % 13)) % mod;
    }
    return dp[x][d] = tmp;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    rep(i, 100010) rep(j, 13) dp[i][j] = -1;
    dp[0][0] = 0;
    cout << calc(0, 0) << endl;

    return 0;
}
