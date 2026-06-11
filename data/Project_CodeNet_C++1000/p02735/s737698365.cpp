#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using db = double;
using vi = vector<int>;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define debug(x) cout << #x <<"\t" << x <<endl
const int inf = 0x3f3f3f3f;
const db eps = 1e-8;
const int mod = 1e9+7;
ll qpow(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1)ret = ret*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return ret;
}
int h, w;
char g[110][110];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w;
	for(int i=1; i<=h; ++i){
		cin >> g[i]+1;
	}
	int dp[110][110];
	memset(dp, 0x3f, sizeof(dp));
	dp[1][1] = g[1][1]=='.'?0:1;
	for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			if(i==1&&j==1)continue;
			dp[i][j] = min(dp[i][j], dp[i-1][j]+(g[i-1][j]=='.'&&g[i][j]=='#'));
			dp[i][j] = min(dp[i][j], dp[i][j-1]+(g[i][j-1]=='.'&&g[i][j]=='#'));
		}
	}
	cout<< dp[h][w];
}



