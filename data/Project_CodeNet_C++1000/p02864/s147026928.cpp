#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
const int maxn=305;
int n,k;
ll a[maxn],dp[maxn][maxn];
int main(){
	scanf("%d%d",&n,&k);
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		dp[i][0]=0;
		dp[i][1]=a[i];
	}
	for(int j=2;j<=n-k;j++)
		for(int i=j;i<=n;i++)
			for(int l=1;l<=i-1;l++)
			    dp[i][j]=min(dp[i][j],dp[l][j-1]+max(0ll,a[i]-a[l]));
	ll ans=INF;
	for(int i=1;i<=n;i++) ans=min(ans,dp[i][n-k]);
	printf("%lld\n",ans);
	return 0;
}