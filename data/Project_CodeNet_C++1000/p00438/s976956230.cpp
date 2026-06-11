#include<stdio.h>
#include<string.h>

int main(void){
	int w,h,x,y,n;
	int dp[17][17];
	
	for(;;){
		scanf("%d%d",&w,&h);
		if(w==0 || h==0)break;
		scanf("%d",&n);
		for(int i=0;i<17;i++)for(int j=0;j<17;j++)dp[i][j]=1;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			dp[x-1][y-1]=0;
		}
		for(int i=0;i<w;i++){
			for(int j=0;j<h;j++){
				if(dp[i][j]!=0){
					if(i!=0 || j!=0)dp[i][j]=0;
					if(i!=0)dp[i][j]+=dp[i-1][j];
					if(j!=0)dp[i][j]+=dp[i][j-1];
				}
			}
		}
		printf("%d\n",dp[w-1][h-1]);
	}
	
	return 0;
}