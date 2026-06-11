#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define print(n) cout<<n<<endl
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
const int M=200111;
const int inf=1000000007;
const long long INF=1e18;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};


/*
vvl comb(int n, int r) {
	vvl v(n + 1,vl(n + 1, 0));
	for (int i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (int j = 1; j < v.size(); j++) {
		for (int k = 1; k < j; k++) {
			v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
		}
	}
	return v;
}
*/

void sosu(ll x,bool f[]){
	ll y=x;
	for(ll i=2;i<=sqrt(y);i++){
		if(x%i==0){
			x/=i;
			f[i]=true;
			i--;
		}
	}
}

ll __gcd(ll x,ll y){
	if(x<y)swap(x,y);
	while(1){
		ll tmp=x%y;
		x=y;
		y=tmp;
		if(y==0)break;
	}
	return x;
}


int main(){
	ll n,m,s[M],t[M];
	cin>>n>>m;
	ll dp[2001][2001]={};
	rep(i,0,n)cin>>s[i];
	rep(i,0,n+1)dp[i][0]=1;
	rep(j,0,m)cin>>t[j];
	rep(j,0,m+1)dp[0][j]=1;

	rep(i,1,n+1){
		rep(j,1,m+1){
			dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
			if(s[i-1]==t[j-1])dp[i][j]+=dp[i-1][j-1];
			dp[i][j]=(dp[i][j]+inf)%inf;
		}
	}

	print(dp[n][m]);
}
