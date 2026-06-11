#include <bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
#define pi pair<int,int>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1005;
const int maxm = 100;
const int inf = 2147483647;
typedef long long ll;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
ll qpow(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}
int n,m,a[maxn],st[maxn],dp[maxn][1<<12];
void print(int x){
	vector<int>ans;
	FOR(i,0,n)if((1<<i)&x)ans.push_back(1);else ans.push_back(0);
	ROF(i,ans.size()-1,0)printf("%d",ans[i]);
	printf("\n");
}
int dfs(int cur,int sta){
	if(cur==m)return sta==((1<<n)-1)?0:inf/2;
	int &ans=dp[cur][sta];
	if(ans<inf/4)return ans;
	if((sta|st[cur+1])!=sta){
		ans=min(ans,dfs(cur+1,sta|st[cur+1])+a[cur+1]); 
	}
	ans=min(ans,dfs(cur+1,sta));
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m+1){
		int k;
		scanf("%d%d",&a[i],&k);
		while(k--){
			int u;
			scanf("%d",&u);
			st[i]|=(1<<(u-1));
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[m][(1<<n)-1]=0;
	ROF(i,m-1,0)
	FOR(j,0,1<<n){
		if((j|st[i+1])!=j){
			dp[i][j]=min(dp[i][j],dp[i+1][j|st[i+1]]+a[i+1]);
		}
		dp[i][j]=min(dp[i][j],dp[i+1][j]);
	}
	int ans=dp[0][0];
	if(ans>=inf/4)ans=-1;
	printf("%d\n",ans);
}