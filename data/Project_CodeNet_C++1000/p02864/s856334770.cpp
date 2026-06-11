#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
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
	ll n,k;cin >> n >> k;
	vector<ll> h(n+1);
	REP(i,n) cin >> h[i+1];
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,INF));
	dp[0][0]=0;
	REP(i,n){
		REP(j,n+1){
			REP(l,i+1){
				chmin(dp[i+1][j+1],dp[l][j]+max(0LL,h[i+1]-h[l]));
			}
		}
	}
	ll ans=INF;
	REP(i,n+1){
		chmin(ans,dp[i][n-k]);
	}
	cout << ans << endl;
}