#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653

int main(){
	vector<vector<ll>> dp(2100,vector<ll>(2100));
	ll n; cin >> n;
	vector<vector<ll>> al(n,vector<ll>(2));
	REP(i,n){
		cin >> al.at(i).at(0);
		al.at(i).at(1) = i;
	}
	sort(al.begin(), al.end()); reverse(al.begin(), al.end());
	REP(i,2100) REP(j,2100){
		if (i==0 && j==0){
			continue;
		}
		else if (i+j>n){
			continue;
		}
		else if (i==0){
			dp[i][j] = dp[i][j-1]+al[i+j-1][0]*abs(n-j-al[i+j-1][1]);
		}
		else if (j==0){
			dp[i][j] = dp[i-1][j]+al[i+j-1][0]*abs(al[i+j-1][1]-i+1);
		}
		else {
			ll x = dp[i][j-1]+al[i+j-1][0]*abs(n-j-al[i+j-1][1]);
			ll y = dp[i-1][j]+al[i+j-1][0]*abs(al[i+j-1][1]-i+1);
			dp[i][j] = max(x,y);
		}
	}
	ll ans = 0;
	FOR(i,0,n){
		ans = max(ans,dp[i][n-i]);
	}
	cout << ans << endl;
}