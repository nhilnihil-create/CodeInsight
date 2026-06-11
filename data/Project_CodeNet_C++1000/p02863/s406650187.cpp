#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e6+3)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
vector<ll>dp(6050,-INF);
int main()
{
	int n,t;
	cin>>n>>t;
	vector<PII>p(n);
	for(int i=0;i<n;i++)cin>>p[i].fi>>p[i].se;
	sort(all(p));
	dp[0] = 0;
	for(int i=0;i<n;i++){
		for(int j=6001;j-p[i].fi>=0;j--){
			if(dp[j-p[i].fi] == -INF)continue;
			if(j > t && j-p[i].fi < t)dp[j] = max(dp[j],dp[j-p[i].fi]+p[i].se);
            else if(j<=t)dp[j] = max(dp[j],dp[j-p[i].fi]+p[i].se);
		}
	}
	ll ans = 0;
	for(int i=0;i<6050;i++)ans = max(ans,dp[i]);
	cout<<ans;
	
}
