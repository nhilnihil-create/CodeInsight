#include<stdio.h>
int dp[50001];
int main(void){
	int i,j;
	int n,m;
	scanf("%d %d",&n,&m);
	for(j=0;j<=n;j++){
		if(j==0){
			dp[j]=0;
		}
		else {
			dp[j]=100000;
		}
	}
	int a;
	for(i=0;i<m;i++){
		scanf("%d",&a);
		for(j=0;j<n;j++){
			if(dp[j]>=0 && j+a<=n && dp[j+a]>dp[j]+1 ){
				dp[j+a]=dp[j]+1;
			}
		}
		/*for(j=0;j<=n;j++){
			printf("%d ",dp[j]);
		}
		printf("\n");*/
	}
	printf("%d\n",dp[n]);
	return 0;
}