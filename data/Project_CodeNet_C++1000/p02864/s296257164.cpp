#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 4611686018427387903;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main(){
	int n, k; cin >> n >> k;
	VI h(n+2); h[0]=0; h[n+1]=0;
	REP(i,n) cin >> h[i+1];
	VVI dp(n+10,VI(n+10,INF));
	dp[0][0]=0;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=i;j++){
			REP(l,k+1){
				if(l+j-1<=k){
					ll cost=dp[i-j][l];
					if(h[i]>h[i-j])
						cost+=h[i]-h[i-j];
					dp[i][l+j-1]=min(cost,dp[i][l+j-1]);
				}
			}
		}
	}
	ll ans=INF;
	REP(i,k+1)
		ans=min(ans,dp[n+1][i]);
	cout << ans << endl;
	return 0;
}