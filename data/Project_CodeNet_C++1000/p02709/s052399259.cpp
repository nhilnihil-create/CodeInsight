#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

typedef struct infant{
	int pos;
	ll a;
}infant;

int main()
{
	int n;
	cin>>n;
	vector<infant> ift(n);
	rep(i,n){
		ll x;
		cin>>x;
		ift[i] = {i+1,x};
	}

	sort(all(ift),
		[&](infant x, infant y){
			return x.a > y.a;
		});


	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));

	rep(i,n){
		rep(j,n){
			if(i+j>=n) continue;
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + ift[i+j].a*(abs(ift[i+j].pos-(i+1))));
			dp[i][j+1] = max(dp[i][j+1], dp[i][j] + ift[i+j].a*(abs(ift[i+j].pos-(n-j))));
		}
	}

	ll ans=0;
	rep(i,n+1){
		ans = max(ans,dp[i][n-i]);
	}
	cout<<ans<<endl;

	return 0;
}