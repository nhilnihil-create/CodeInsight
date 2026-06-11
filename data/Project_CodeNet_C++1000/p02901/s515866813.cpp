#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define ve vector
const int INF = 2e9;
int main(){
    int n,m;
    cin >> n >> m;
    ve<int> a(m),b(m);
    ve<ve<int>> c(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        rep(j,b[i]){
            int c0;
            cin >> c0;
            c0--;
            c[i].push_back(c0);
        }
    }
    ve<int> dp(1<<n,INF);
    dp[0] = 0;
    rep(i,m){
        int mask=0;
        for(int ci: c[i]){
            mask |= 1<<ci;
        }
        ve<int> p(1<<n);
        p = dp;
        rep(j,1<<n){
            dp[j|mask] = min(dp[j|mask],min(p[j|mask], p[j] + a[i]));
        }
    }
    if(dp[(int)(1<<n)-1] == INF)dp[(int)(1<<n)-1] = -1;
    cout << dp[(int)(1<<n)-1] << endl;
    return 0;
}