#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//input
string n;
ll l;

ll dp[1000100][2];

int main(){
    cin >> n;
    l = n.size();
    rep(i,1000100){
        rep(j,2){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=1;i<=l;i++){
        int now = n[i-1]-'0';
        chmin(dp[i][1],dp[i-1][0]+10-now);
        chmin(dp[i][1],dp[i-1][1]+9-now);

        chmin(dp[i][0],dp[i-1][1]+now+1);
        chmin(dp[i][0],dp[i-1][0]+now);
    }
    ll ans = INF;
    chmin(ans,dp[l][0]);
    chmin(ans,dp[l][1]+1);
    cout << ans << endl;
    return 0;
}