#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,t;cin >> n >> t;
    vector<int> a(n),b(n);
    REP(i,n){
        cin >> a[i] >> b[i];
    }
    int dp[n+1][t][2]={};
    REP(i,n){
        REP(j,t){
            REP(k,2){
                chmax(dp[i+1][j][k],dp[i][j][k]);
                if(j+a[i]<t){
                    chmax(dp[i+1][j+a[i]][k],dp[i][j][k]+b[i]);
                }
                if(!k){
                    chmax(dp[i+1][j][1],dp[i][j][0]+b[i]);
                }
            }
        }
    }
    int ans=0;
    REP(i,t){
        REP(j,2){
            chmax(ans,dp[n][i][j]);
        }
    }
    cout << ans << endl;
}