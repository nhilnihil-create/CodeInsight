//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<int, pi> node;
#define oset tree<pi, null_type,greater<pi>, rb_tree_tag,tree_order_statistics_node_update>

#define N 2003
lli dp[N][N], mod = 1e9+7;
int a[N], b[N];


int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int j=1; j<=m; j++) cin >> b[j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i] == b[j]){
                dp[i][j] = (1+dp[i-1][j]+dp[i][j-1])%mod;
            }
            else{
                dp[i][j] = (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod+mod+mod)%mod;
            }
        }
    }
    lli ans = (dp[n][m]+1) % mod;

    cout << ans << "\n";

    return 0;
}
