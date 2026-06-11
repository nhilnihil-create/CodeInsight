#include<stdio.h>


long long int dp[105][25]={};
int n;
int dat[105];

int main(void){
	
	scanf("%d",&n);
	
	int i,t1,t2,s;
	
	for(i=1;i<=n;i++){
		scanf("%d",&dat[i]);
	}
	
	for(i=0;i<=20;i++){
		dp[1][i]=0;
	}
	dp[1][dat[1]]=1;
	
	for(i=2;i<=n-1;i++){
		for(s=0;s<=20;s++){
			dp[i][s]=0;
			t1 = s + dat[i];
			if(0<=t1 && t1<=20){
				dp[i][s] += dp[i-1][t1];
			}
			t2 = s - dat[i];
			if(0<=t2 && t2<=20){
				dp[i][s] += dp[i-1][t2];
			}
		}
	}
	
	long long int ans = dp[n-1][dat[n]];
	printf("%lld\n",ans);
	return 0;
}