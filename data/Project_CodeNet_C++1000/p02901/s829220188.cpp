#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = ll(1e18)+5;

int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> c(M);
    vector<ll> a(M);
    for(int i=0;i<M;i++){
        int b;
        cin >> a[i] >>b;
        ll val =0;
        for(int j=0;j<b;j++){
            int t;
            cin >>t;
            --t;
            val |= (1<<t);
        }
        c[i] = val;
    }
    ll dp[M+1][1<<N];
    for(int i=0;i<(1<<N);i++){
        for(int j=0;j<M+1;j++){
            dp[j][i] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i=0;i<M;i++)for(int j=0;j<(1<<N);j++){
        // cerr <<"i="<<i <<"c[i]=" <<bitset<8>(c[i]) <<" j=" << bitset<8>(j) << endl;
        dp[i+1][j|c[i]] = min(dp[i+1][j|c[i]],dp[i][j]+a[i] );
        dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
        // cerr <<"dp[i+1][j|c[i]]=" << dp[i+1][j|c[i]] << endl;
    }
    if(dp[M][(1<<N)-1] == INF){
        dp[M][(1<<N)-1] = -1;
    }
    cout << dp[M][(1<<N)-1] << endl;

    return 0;
}