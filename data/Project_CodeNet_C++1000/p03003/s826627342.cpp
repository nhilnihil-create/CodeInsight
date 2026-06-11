#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
const int modn=1e9+7;
int a[maxn],b[maxn];
ll dp[maxn][maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=0;i<=n;i++)dp[i][0]=1;
	for(int i=0;i<=m;i++)dp[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=((dp[i-1][j]+dp[i][j-1])%modn-dp[i-1][j-1]+modn)%modn;
			if(a[i]==b[j])dp[i][j]=(dp[i][j]+dp[i-1][j-1])%modn;
		}
	}
	printf("%lld\n",dp[n][m]);
}