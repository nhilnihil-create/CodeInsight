#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tet"
using namespace std;
const ll N = 3e3 + 9;
const ll mod = 998244353;
typedef pair<ll,ll> LL;

ll dp[N][N],n,S,a[N],i,j;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n>>S;
    for (i = 1;i <= n;i++) cin>>a[i];
    dp[0][0] = 1;
    for (i = 1;i <= n;i++){
        for (j = 0;j <= S;j++){
            dp[i][j] += 2*dp[i - 1][j];
            if (j >= a[i]) dp[i][j] += dp[i - 1][j - a[i]];
            dp[i][j] %= mod;
        }
    }
    cout<<dp[n][S];
}
