#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1e9+5;
const int N=2e5+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

ll dp[2005][2005];

void max_self(ll& a,ll b){
	if(b>a) a=b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<ll,int>> a;
	for(int i=0;i<n;++i){
		ll x;
		cin>>x;
		a.emplace_back(x,i);
	}
	sort(all(a));
	reverse(all(a));
	for(int l=0;l<n;++l){
		for(int r=0;r<n-l;++r){
			ll num=a[l+r].first;
			int id=a[l+r].second;
			//~ if(!l&&!r){
				//~ cout<<id-l<<" ~ "<<n-1-r-id<<endl;
			//~ } 
			max_self(dp[l+1][r],dp[l][r]+num*(id-l));
			max_self(dp[l][r+1],dp[l][r]+num*(n-1-r-id));
		}
	}
	ll ans=0;
	for(int i=0;i<n;++i) max_self(ans,dp[i][n-i]);
	cout<<ans;
	return 0;
}
