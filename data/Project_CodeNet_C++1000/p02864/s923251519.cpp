#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll dp[305][305][305];

int main(){
    int n, k; cin >> n >> k;
    vector<ll> h(n+1);
    FOR(i, 1, n+1) cin >> h[i];

    rep(i,n+1){
        rep(j,n+1){
            rep(s,n+1){
                dp[i][j][s] = 1e18;
            }
        }
    }

    dp[0][0][0] = 0;

    rep(i, n){
        int m = min(i, k);
        rep(j, m+1){
            rep(s, j+1){
                chmin(dp[i+1][j][0], dp[i][j][s] + max(0LL, h[i+1] - h[i-s]));

                chmin(dp[i+1][j+1][s+1], dp[i][j][s]);
            }
        }
    }

    ll ans = 1e18;
    rep(j, k+1){
        rep(s, j+1){
            chmin(ans, dp[n][j][s]);
        }
    }
    cout << ans << endl;
}
