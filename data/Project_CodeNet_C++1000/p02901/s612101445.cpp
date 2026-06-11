#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e16;

int n,m;
ll dp[1100][5000];

int main(){
    cin >> n >> m;
    vector<ll>a(m),b(m),c(m,0);
    rep(i,m){
        cin >> a[i] >> b[i];
        rep(j,b[i]){
            int t;
            cin >> t;
            t--;
            c[i]+=(1<<t);
        }
    }
    rep(i,1010){
        rep(j,4500){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    rep(i,m){
        rep(j,1<<n){
            chmin(dp[i+1][j],dp[i][j]);
            chmin(dp[i+1][j|c[i]],dp[i][j]+a[i]);
        }
    }
    if(dp[m][(1<<n)-1]==INF){
        cout << -1 << endl;
    }
    else{
        cout << dp[m][(1<<n)-1] << endl;
    }

    return 0;
}

