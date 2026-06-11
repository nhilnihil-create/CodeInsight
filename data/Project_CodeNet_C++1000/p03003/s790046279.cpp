#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define ve vector
const int mod = 1000000007;
int main(){
    int n,m;
    cin >> n >> m;
    ve<int> s(n), t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    ve<ve<ll>> dp0(n+3,ve<ll>(m+3));
    ve<ve<ll>> dp1(n+3,ve<ll>(m+3));

    dp0[0][0] = 1;

    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            (dp0[i+1][j] += dp0[i][j]) %=mod;
            (dp1[i][j] += dp0[i][j]) %= mod;
            (dp1[i][j+1] += dp1[i][j]) %= mod;
            if(s[i] == t[j]){
                (dp0[i+1][j+1] += dp1[i][j]) %= mod;
            }
        }
    }
    cout << dp1[n][m] << endl;
    return 0;
}