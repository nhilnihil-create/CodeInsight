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

int dp[100010][2];
string L;
int calc(int x, int smaller) {
    if (x == L.length()) return dp[x][smaller] = 1;
    else if (dp[x][smaller] > 0) return dp[x][smaller];
    if(!smaller) {
        if (L[x] == '0')
            return dp[x][smaller] = (calc(x + 1, 0)) % mod;
        else
            return dp[x][smaller] = (calc(x + 1, 0) * 2 + calc(x + 1, 1)) % mod;
    } else {
        return dp[x][smaller] = (calc(x + 1, 1) * 3) % mod;
    }  
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> L;
    cout << (calc(0, 0)) % mod << endl;

    return 0;
}
