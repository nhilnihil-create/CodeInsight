#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> c(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        rep(j,b[i]){
            cin >> c[i][j];
            --c[i][j];
        }
    }
    vector<int> dp((1<<n), INF);
    dp[0] = 0;
    rep(S,(1<<n)){
        if(dp[S] == INF) continue;
        rep(i,m){
            int nextS = S;
            rep(j,b[i]){
                nextS |= (1<<c[i][j]);
            }
            chmin(dp[nextS], dp[S] + a[i]);
        }
    }
    if(dp[(1<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;
    return 0;
}