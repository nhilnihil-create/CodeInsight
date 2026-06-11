#include<bits/stdc++.h>
#define fi first #define se second
using namespace std; typedef long long ll;
const int MAXN = 10 + 3e3;
const ll oo = 1 + 1e18, mod = 7 + 1e9;

ll n, m, a[MAXN], b[MAXN]; long long f[MAXN][MAXN];

int main(){
    #define TASK "ABC"
    #ifndef ONLINE_JUDGE
    freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
    #endif ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i][0] = 1ll;
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
        f[0][i] = 1ll;
    }

    f[0][0] = 1ll;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            f[i][j] = (f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] * 1ll * (a[i] != b[j]) + mod) % mod;

        }
    }

    cout << f[n][m];




    return 0;
}
