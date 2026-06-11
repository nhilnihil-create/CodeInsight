#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dp[3005][3005];
int main() {
	ll n,t;
	cin>>n>>t;
	vector<pair<ll,ll>>a;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		a.push_back(make_pair(x,y));
	}
	sort(a.begin(),a.end());
	for(ll i=0;i<n;i++){
		for(ll j=0;j<=3000;j++){
			ll x=a[i].first;
			ll y=a[i].second;
							dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+x<=3000){
				dp[i+1][j+x]=max(dp[i+1][j+x],dp[i][j]+y);
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans=max(ans,dp[i][t-1]+a[i].second);
	}
//	cout << dp[1][59]<<endl;;
	cout <<ans;
	// your code goes here
	return 0;
}