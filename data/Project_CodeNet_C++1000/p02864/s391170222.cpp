#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, k;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> k;
	ll h[n+1];
	h[0] = 0;
	rep(i, 1, n){cin >> h[i];}

	ll dp[n+1][n+1][k+1];
	rep(i, 0, n){
		rep(j, 0, n){
			rep(ki, 0, k){
				dp[i][j][ki] = INF;			
			}
		}	
	}
	dp[0][0][k] = 0;
	
	rep(i, 1, n){
		rep(j, 0, i){
			rep(ki, max(k-i, 0LL), k){
				if(dp[i-1][j][ki] != INF){
					dp[i][i][ki] = min(dp[i-1][j][ki]+max(h[i]-h[j], 0LL), dp[i][i][ki]);
				}
				if(ki < k && dp[i-1][j][ki+1] != INF){
					dp[i][j][ki] = min(dp[i-1][j][ki+1], dp[i][j][ki]);
				}
			}
		}
	}
	
	//rep(i, 1, n){rep(j, 0, i){rep(ki, 0, k){cout << i << " " << j << " " << ki << " " << dp[i][j][ki] << endl;}}}
	
	ll ans = INF;
	rep(j, 0, n){
		ans = min(dp[n][j][0], ans);
	}
	print(ans)
	return 0;
}