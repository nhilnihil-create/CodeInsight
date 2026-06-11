#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
const ll INF = 1e15;
const int MX = 305;
int n,k,h[MX],un[MX],e;
ll dp[MX][MX][MX],ans=INF;
map<int,int> zp;
int main(){
	scanf("%d%d", &n, &k);
	rep(i,n){
		scanf("%d", h+i);
		un[i] = h[i];
	}
	sort(un, un+n+1);
	e = (int)(unique(un,un+n+1) - un);
	rep(i,e) zp[un[i]] = i;
	fill(dp[0][0],dp[n+1][k+1],INF);
	dp[0][0][0] = 0;
	rep(i,n+1){
		rep(j,k+1) rep(l,e){
			dp[i+1][j][zp[h[i]]] = min(dp[i+1][j][zp[h[i]]], dp[i][j][l] + (h[i] < un[l] ? un[l] - h[i]: 0));
		}
		if(i<n) rep(j,k) rep(l,e) dp[i+1][j+1][l] = min(dp[i+1][j+1][l], dp[i][j][l]);
	}
	rep(i,e) ans = min(ans,dp[n+1][k][i]);
	printf("%lld\n", ans);
}