#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2010;
ll a[N],n,b[N],ans;
ll dp[N][N];
ll m[N],vis[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		//printf("%lld ",a[i]);
		b[i]=a[i];
	}
	//printf("\n");
	sort(b+1,b+n+1,cmp);
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j){
			if(b[i]==a[j]&&!vis[j]){
				vis[j]=1;
				m[i]=j;
				break;
			}
		}
	}
//	for(ll i=1;i<=n;++i){
//		printf("%lld\n",m[i]);
//	}
	for(ll s=1;s<=n;++s){
		dp[s][0]=dp[s-1][0]+b[s]*(m[s]-s);
		dp[0][s]=dp[0][s-1]+b[s]*(n+1-s-m[s]);
		//printf("i=%lld,dp[%lld][0]=%lld,dp[0][%lld]=%lld\n",m[s],s,dp[s][0],s,dp[0][s]);
		for(ll x=1,y=s-1;x<s;++x,--y){
			dp[x][y]=max(dp[x][y-1]+b[s]*(n+1-y-m[s]),dp[x-1][y]+b[s]*(m[s]-x));
			//printf("dp[%lld][%lld]=%lld\n",x,y,dp[x][y]);
		}
	}
	for(ll i=0;i<=n;++i){
		if(ans<dp[i][n-i]) ans=dp[i][n-i];
	}
	printf("%lld",ans);
}
