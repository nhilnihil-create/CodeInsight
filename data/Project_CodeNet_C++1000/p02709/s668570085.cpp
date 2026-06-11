#pragma GCC optimize("Ofast")
#include<stdio.h>
#include<algorithm>
using namespace std;
long long dp[2005][2005]={0};
struct Num{
	long long val,id;
}num[2005];
bool cmp(Num a,Num b){
	return a.val>b.val;
}
int main(){
	long long i,j,n;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&num[i].val);
		num[i].id=i;
	}
	sort(num,num+n,cmp);
	dp[1][0]=num[0].id*num[0].val;
	dp[0][1]=(n-1-num[0].id)*num[0].val;
	for(i=2;i<=n;i++)
		for(j=0;j<=i;j++)
			dp[j][i-j]=max((j?(dp[j-1][i-j]+abs(num[i-1].id-j+1)*num[i-1].val):0),((i-j)?(dp[j][i-j-1]+abs(n-i+j-num[i-1].id)*num[i-1].val):0));
	long long ans=0;
	for(i=0;i<=n;i++)
		ans=max(ans,dp[i][n-i]);
	printf("%lld\n",ans);
}
