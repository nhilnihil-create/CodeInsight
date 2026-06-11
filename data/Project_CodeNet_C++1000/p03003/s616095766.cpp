#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <queue>
#define inp(X) cin >> X
#define out(X) cout << X << endl
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define MAX(A) *max_element(A.begin(),A.end())
#define MIN(A) *min_element(A.begin(),A.end())
#define SORT(A) sort(A.begin(),A.end())
using namespace std;

typedef long long int ll;
#define MOD 1000000007
#define INF 1000000001

ll gcd(ll x, ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}

bool bfs(vector<vector<int>> g, vector<int> &dist, int sv)
{
	queue<int> q;
	q.push(sv);
	dist[sv]=0;
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto v : g[now]){
			if(dist[v]!=-1) continue;
			dist[v] = dist[now]+1;
			q.push(v);
		}
	}
}

int main(void) {
	ll n,m; cin >> n >> m;
	vector<ll> s(n),t(m);
	rep(i,n) cin >> s[i];
	rep(j,m) cin >> t[j];
	vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
	vector<vector<ll>> sum(n+1,vector<ll>(m+1,0));
	dp[0][0]=1;
	rep(i,n+1) sum[i][0]=1;
	rep(j,m+1) sum[0][j]=1;
	rep2(i,1,n+1)rep2(j,1,m+1){
		if(s[i-1]==t[j-1]) dp[i][j] = sum[i-1][j-1];
		else dp[i][j]=0;
		sum[i][j] += sum[i-1][j]; sum[i][j] %= MOD;
		sum[i][j] += sum[i][j-1]; sum[i][j] %= MOD;
		sum[i][j] -= sum[i-1][j-1]; if(sum[i][j]<0)sum[i][j] += MOD;
		sum[i][j] += dp[i][j];sum[i][j] %= MOD;
	}
/* 	rep(i,n+1){
		rep(j,m+1) cout << dp[i][j] << " ";
		cout << endl;
	} */
	out(sum[n][m]);
}


