#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

long int M = 1e+9+7;
int main(void){
    int n;
    cin >> n;
    vi a(n), mx(n);
    rep(i,n){
        cin >> a[i];
    }
    vi a_cp(n);
    a_cp = a;
    rep(i,n){
        int mxj=0;
        srep(j,1,n){
            if(a_cp[j] > a_cp[mxj]) mxj = j;
        }
        mx[i] = mxj;
        a_cp[mxj] = 0;
    }
    /*
    rep(i,n){
        cout << a[mx[i]] << endl;
    }
    */
    vvl dp(n+1,vl(n+1));
    rep(i,n){
        int pi = mx[i];
        rep(l,i+1){
            int r = i-l;
            chmax(dp[i+1][l], dp[i][l]+ll((n-r-1)-pi)*a[pi]);
            dp[i+1][l+1] = dp[i][l]+ll(pi-l)*a[pi];
        }
    }
    /*
    rep(i,dp.size()){
        rep(j,dp[i].size()){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    ll ans=0;
    rep(i,n+1) chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}