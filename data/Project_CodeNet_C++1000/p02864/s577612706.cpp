/*
Website : https://atcoder.jp/contests/abc145/tasks/abc145_f
Problem : F - Laminate
Method  : dp
Status  : 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int maxn=305;
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {
		if (ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*neg;
}
int dp[maxn][maxn];
int n,k;
int num[maxn];
signed main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=n;++i) num[i]=read();
	for (int i=1;i<=n;++i) dp[i][1]=num[i];
	for (int i=1;i<=n;++i) {
		for (int j=2;j<=n-k;++j) {
			dp[i][j]=inf;
			for (int l=1;l<i;++l) {
				dp[i][j]=min(dp[i][j],dp[l][j-1]+max(0ll,num[i]-num[l]));
			}
		} 
	} 
	int ans=inf;
	for (int i=1;i<=n;++i) {
		ans=min(ans,dp[i][n-k]);
	}
	printf("%lld\n",ans);
	return 0;
}
