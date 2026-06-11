#include<iostream>

int n,a[100];
int b,i,j;
unsigned long long int dp[102][22];

int main(void){
	scanf("%d",&n);
	for(b=0;b<n;b++){
		scanf("%d", &a[b]);
	}
	dp[1][a[0]]=1;
	for(i=1;i<n-1;i++){
		for(j=0;j<=20;j++){
			if(dp[i][j]>0){
				int plus=j+a[i];
				int minus=j-a[i];
        	                if(plus>=0 && plus<=20){
					dp[i+1][plus]+=dp[i][j];
				}
				if(minus>=0 && minus<=20){
					dp[i+1][minus]+=dp[i][j];
				}
			}
		}
	}
	
	printf("%llu\n",dp[n-1][a[n-1]]);
	return 0;
}