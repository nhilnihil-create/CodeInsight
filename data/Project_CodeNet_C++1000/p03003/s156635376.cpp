#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 2e3 + 5, M = 1e5 + 5;

int n, m, a[N], b[N];
ll dp[N][N][3], MOD(1e9 + 7);

ll solve(int i, int j, int men){
    if(i == n || j == m)return 0;
    ll &ret = dp[i][j][men];
    if(~ret)return ret;
    ret = 0;
    if(men == 0){
        ret = (ret + solve(i, j, men + 1)) % MOD;
        ret = (ret + solve(i, j + 1, men)) % MOD;
    }
    else if(men == 1){
        ret = (ret + solve(i, j, men + 1)) % MOD;
        ret = (ret + solve(i + 1, j, men)) % MOD;
    }
    else if(men == 2 && a[i] == b[j])
        ret = (ret + solve(i + 1, j + 1, 0) + 1) % MOD;
    return ret;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < n ; ++i)scanf("%d", a + i);
    for(int i = 0 ; i < m ; ++i)scanf("%d", b + i);
    memset(dp, -1, sizeof dp);
    ll ans = solve(0, 0, 0) + 1;
    printf("%lld\n", ans % MOD);
}