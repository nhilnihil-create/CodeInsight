#pragma GCC optimize("O4")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
//#define MOD (ll)(998244353)
#define MOD (ll)(1e9+7)
#define INF (1e17)
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int fpow(int b,int p){
	b%=MOD;
	int ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int dp[310][310];

int32_t main() {
#ifdef LOCAL_TEST
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\input.in","r",stdin);
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\output.out","w",stdout);
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	//code...
	int n,k; cin>>n>>k;
	vector<int> v(n+1);
	v[0]=0;
	For(i,1,n) cin>>v[i];
	For(i,0,n) dp[i][1]=v[i],dp[i][0]=0;
	For(i,1,n) dp[0][i]=INF;
	For(i,1,n) For(j,2,n-k){
		dp[i][j]=INF;
		For(l,0,i-1) dp[i][j]=min(dp[i][j],dp[l][j-1]+max(0ll,v[i]-v[l]));
		cerr<<dp[i][j]<<"\t\n"[j==n];
	}
	int ans=INF;
	For(i,0,n) ans=min(ans,dp[i][n-k]);
	cout<<ans<<"\n";
	return 0;
}
